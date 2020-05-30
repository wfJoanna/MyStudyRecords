#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int fd[2];
	pipe(fd);
	pid_t pid1,pid2;
	char buf[80];
	ssize_t len;

	if((pid1 = fork()) == 0){
		close(fd[0]);
		write(fd[1],"Child process 1 is sending a message!\n",38);
		return 0;
	}
	waitpid(pid1,NULL,0);

	if((pid2 = fork()) == 0){
		close(fd[0]);
		write(fd[1],"Child process 2 is sending a message!\n",38);
		return 0;
	}
	waitpid(pid2,NULL,0);

	close(fd[1]);
	len = read(fd[0],buf,76);
	write(STDOUT_FILENO,buf,len);

	return 0;
}
