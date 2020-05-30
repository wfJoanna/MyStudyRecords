# MyStudyRecords  

存放我学习过程中写的一些代码  

# 2019年年末  

## UNIX实验课shell程序：  

1. [文本建立与键盘输入](https://github.com/wfJoanna/MyStudyRecords/blob/master/%E6%96%87%E6%9C%AC%E5%BB%BA%E7%AB%8B%E4%B8%8E%E9%94%AE%E7%9B%98%E8%BE%93%E5%85%A5)  

将用户从键盘输入的文本附加到一个指定的文件中。如果该文件不存在，则新建立该文件；如果该文件已经存在，则把键盘输入的文本附加到该文件后面。输入内容及行数不限定，以空行表示输入结束。运行结束时显示该文件内容。  

2. [用户登录检测](https://github.com/wfJoanna/MyStudyRecords/blob/master/%E7%94%A8%E6%88%B7%E7%99%BB%E5%BD%95%E6%A3%80%E6%B5%8B)  

程序运行时首先列出当前系统中的已登录用户的名单，再检查指定用户是否已登录。如果已登录，则显示相应信息；如果未登录，则等待该用户登录，直到指定用户登录进入系统为止。  

3. [文件状态查询](https://github.com/wfJoanna/MyStudyRecords/blob/master/%E6%96%87%E4%BB%B6%E7%8A%B6%E6%80%81%E6%9F%A5%E8%AF%A2)  

动态检测指定文件的状态信息，当文件的大小发生改变时，给出提示信息，并继续前进检测。当文件的大小的变化次数或持续检查无变化次数达到一定值时，退出检查，程序结束。  

# 2020年5月  

## 操作系统实验课： 

1. 哲学家就餐问题  

在Unix系统下实现教材2.5.2节中所描述的哲学家就餐问题。5个哲学家，5根筷子。可以显示出每个哲学家的工作状态，如吃饭，思考。连续运行30次都未出现死锁现象。    

[法一](https://github.com/wfJoanna/MyStudyRecords/blob/master/%E5%93%B2%E5%AD%A6%E5%AE%B6%E5%B0%B1%E9%A4%90(%E6%B3%95%E4%B8%80).c)    

法一用了信号量和互斥量，避免了死锁，可以多个哲学家一起吃饭，但是不能两个哲学家同时拿筷子    

[法二](https://github.com/wfJoanna/MyStudyRecords/blob/master/%E5%93%B2%E5%AD%A6%E5%AE%B6%E5%B0%B1%E9%A4%90(%E6%B3%95%E4%BA%8C).c)    

法二只用了互斥量，比法一更好。既避免了死锁，还可以多个哲学家同时拿筷子同时吃饭    

2. [生产者/消费者问题](https://github.com/wfJoanna/MyStudyRecords/blob/master/%E7%94%9F%E4%BA%A7%E8%80%85%E6%B6%88%E8%B4%B9%E8%80%85%E9%97%AE%E9%A2%98.c)  

有一群生产者进程在生产产品，并将这些产品提供给消费者进程去消费。为使生产者进程与消费者进程能并发执行，在两者之间设置了一个具有10个缓冲区的缓冲池：生产者进程从文件中读取一个数据，并将它存放到一个缓冲区中；消费者进程从一个缓冲区中取走数据，并输出此数据。   

生产者和消费者之间保持同步原则：不允许消费者进程到一个空缓冲区去取产品；也不允许生产者进程向一个已装满产品且尚未被取走的缓冲区中投放产品；不允许生产者和消费者同时对一个缓冲区下手。  

3. [管道进程通信](https://github.com/wfJoanna/MyStudyRecords/blob/master/%E7%AE%A1%E9%81%93%E8%BF%9B%E7%A8%8B%E9%80%9A%E4%BF%A1.c)  

在Linux系统中使用系统调用fork()创建两个子进程，使用系统调用pipe()建立一个管道，两个子进程分别向管道各写一句话：  

   Child process 1 is sending a message!   

   Child process 2 is sending a message!   

而父进程则从管道中读出来自于两个子进程的信息，显示在屏幕上。然后分别结束两个子进程的运行。子进程1先写，子进程2后写，完了之后父进程才从管道读数据  
