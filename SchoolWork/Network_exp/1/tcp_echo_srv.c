/*
    TCP ECHO单进程循环服务器参考模版
    @2020 电子科技大学 信息与软件工程学院 《计算机网络系统》课程组
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <errno.h>
#define BACKLOG 1024
// 全局变量sig_to_exit，用于指示服务器程序是否退出；
int sig_to_exit = 0;
int sig_type = 0;

// SIGINT信号处理函数；
void sig_int(int signo) {
    // TODO 记录本次系统信号编号；
    sig_type = signo;
	printf("[srv] SIGINT is coming!\n");
    // TODO 设置全局变量，以提示服务器程序释放资源；
    sig_to_exit = 1;
}

// SIGPIPE信号处理函数；
void sig_pipe(int signo) {
    // TODO 记录本次系统信号编号；
    sig_type = signo;
    printf("[srv] SIGPIPE is coming!\n");
}

// 业务逻辑处理函数；
void echo_rep(int sockfd) {
    // TODO 定义数据长度变量len，以及读取结果变量res；
    int len = 0;
    int len_n=0;
	int read_res;
    // TODO 定义缓存指针变量buf;
    char *buf = NULL;
    char *now;
    do{
        // (1) TODO 读取数据长度： res = read(x,x,x);
        /* int型长度变量在读写时请特别注意字节序转换！*/
        read_res = read(sockfd, &len_n, sizeof(len_n));
        len=ntohl(len_n);
        // 以下代码紧跟read();
        if(read_res < 0){
            printf("[srv] read len return %d and errno is %d\n", read_res, errno);
            if(errno == EINTR){
                if(sig_type == SIGINT)
                    return;//但凡收到SIGINT，指示服务器结束
                continue;//若是其他信号中断，则重新执行读取
            }
            return;
        }
        // TODO 若read返回0（并非指定读0字节返回零），return；
        if(read_res == 0){
			return;
		}

        // (2) 按长读取数据；
        // TODO 采用malloc，根据数据长度分配buf；
        int read_amnt = 0, len_to_read = len;
		buf = (char*)malloc(len * sizeof(char));
        char *next=buf;
        do{
            // TODO 按长读取数据： res = read(x,x,x);
            read_res = read(sockfd, next, len_to_read);
            // 以下代码紧跟read();
            if(read_res < 0){
                printf("[srv] read data return %d and errno is %d\n", read_res, errno);
                if(errno == EINTR){
                    if(sig_type == SIGINT){
                        free(buf);
                        return;//但凡收到SIGINT，指示服务器结束
					}
                    continue;//若是其他信号中断，则重新执行读取
                }
                free(buf);
                return;
            }
            // TODO 若read返回0（并非指定读0字节返回零），return；
            if(read_res == 0){
				// printf("[srv] read data return 0.\n");
				free(buf);
				return;
			}
            read_amnt += read_res;
            next=buf+read_amnt;
			if(read_amnt == len){
				//printf("[srv] read done as expected wtih read_amnt[%d]\n", read_amnt);
				break;
			}
			else{
				len_to_read = len - read_amnt;
			}
        }while(1);

        // 本轮数据长度以及数据本身的读取结束：
        // TODO 按题设要求打印接收到的[echo_rqt]信息；
        printf("[echo_rqt] %s\n", buf);
        // TODO 回写客户端[echo_rep]信息；根据读写边界定义，同样需先发长度，再发数据：res = write(x,x,x);res = write(x,x,x);
        write(sockfd, &len_n, sizeof(len_n));
        write(sockfd, buf, len);
        // TODO 发送结束，释放buf；
        free(buf);
    }while(1);
}

int main(int argc,char **argv)
{
    if(argc != 3)
	{
		printf("Usage: tcp_echo_srv <addr> <port>\n");
		return 0;
	}
    // 安装SIGPIPE信号处理器
    struct sigaction sigact_pipe, old_sigact_pipe;
    sigact_pipe.sa_handler = sig_pipe;
    sigemptyset(&sigact_pipe.sa_mask);
    sigact_pipe.sa_flags = 0;
    // 通过SA_RESTART设置受影响的慢调用在中断结束后立刻重启：
    sigact_pipe.sa_flags |= SA_RESTART;
    sigaction(SIGPIPE, &sigact_pipe, &old_sigact_pipe);

    // TODO 安装SIGINT信号处理器
    struct sigaction sigact_int;
    sigact_int.sa_handler = sig_int;
    sigemptyset(&sigact_int.sa_mask);
    sigaddset(&sigact_int.sa_mask, SIGQUIT);
    sigact_int.sa_flags = 0;
    sigaction(SIGINT, &sigact_int, 0);
    // TODO 定义服务器Socket地址srv_addr，以及客户端Socket地址cli_addr；
    char ip_str[20]={0};//用于IP地址转换
	struct sockaddr_in srv_addr;
	struct sockaddr_in cli_addr;
    // TODO 定义客户端Socket地址长度cli_addr_len（类型为socklen_t）；
	socklen_t cli_addr_len;
    int clilen;
    // TODO 定义Socket监听描述符listenfd，以及Socket连接描述符connfd；
    int listenfd, connfd;
    // TODO 初始化服务器Socket地址srv_addr，其中会用到argv[1]、argv[2]
        /* IP地址转换推荐使用inet_pton()；端口地址转换推荐使用atoi(); */
    bzero(&srv_addr, sizeof(srv_addr));

	srv_addr.sin_family = AF_INET;
	inet_pton(AF_INET, argv[1], &srv_addr.sin_addr);
	srv_addr.sin_port = htons(atoi(argv[2]));
    // TODO 按题设要求打印服务器端地址server[ip:port]，推荐使用inet_ntop();
    printf("[srv] server[%s:%d] is initializing!\n", inet_ntop(AF_INET, &srv_addr.sin_addr, ip_str, sizeof(ip_str)), (int)ntohs(srv_addr.sin_port));
    // TODO 获取Socket监听描述符: listenfd = socket(x,x,x);
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    // TODO 绑定服务器Socket地址: res = bind(x,x,x);
    bind(listenfd, (struct sockaddr*)&srv_addr, sizeof(srv_addr));
    // TODO 开启服务监听: res = listen(x,x);
    listen(listenfd,5);
    // 开启accpet()主循环，直至sig_to_exit指示服务器退出；
    while(!sig_to_exit)
    {
        // TODO 获取cli_addr长度，执行accept()：connfd = accept(x,x,x);
        clilen = sizeof(cli_addr);
		connfd = accept(listenfd, (struct sockaddr*)&cli_addr, &clilen);
        // 以下代码紧跟accept()，用于判断accpet()是否因SIG_INT信号退出（本案例中只关心SIGINT）；也可以不做此判断，直接执行 connfd<0 时continue，因为此时sig_to_exit已经指明需要退出accept()主循环，两种方式二选一即可。
        if(connfd == -1 && errno == EINTR && sig_type == SIGINT){
            close(connfd);
            break;
        }
        // 若上述if判断不成立且connfd<0，则重启accept();
        if (connfd < 0)
            continue;

        // TODO 按题设要求打印客户端端地址client[ip:port]，推荐使用inet_ntop();
        printf("[srv] client[%s:%d] is accepted!\n", inet_ntop(AF_INET, &cli_addr.sin_addr, ip_str, sizeof(ip_str)), (int)ntohs(cli_addr.sin_port));
        // TODO 执行业务处理函数echo_rep()，进入业务处理循环;
        echo_rep(connfd);
        // TODO 业务函数退出，关闭connfd;
        close(connfd);
        printf("[srv] connfd is closed!\n");
    }
    // TODO accpet()主循环结束，关闭lstenfd;
    close(listenfd);
    printf("[srv] listenfd is closed!\n");
    printf("[srv] server is going to exit!\n");
    return 0;
}

