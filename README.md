# MyStudyRecords

存放我学习过程中写的一些代码，适合我自己回顾知识的时候看（持续更新）

<br>

| 2018年上半年 | 2019年年末 | 2020年5月 | 2020年7月 | 2020年10月 | 2020年11月 | 2020年12月 |
| :----: | :----: | :----: | :----: | :----: | :----: | :----: |
| [:smile:](#2018年上半年) | [:snowflake:](#2019年年末) | [:books:](#2020年5月) | [:house:](#2020年7月) | [:partly_sunny:](#2020年10月) | [:earth_asia:](#2020年11月) | [:anger:](#2020年12月) |

<br>



# 2018年上半年

## C语言课程在线测试：

这是我步入计算机世界的第一步，当时的我还是个小萌新，刚上大一，为了应对老师布置的在线测试的任务，写的糊里糊涂但是还是AC了的程序们。当时那种为了AC而绞尽脑汁、疯狂debug、AC之后充满自豪与满足的日子，真是单纯而幸福呐​ :relaxed:

上传到这里不为复习，只为记录那段作为萌新的日子

当时觉得自己写出来的程序就像是自己的孩子一样，所以给他们取名叫“Fearless”（取这个名的原因不用我多说了吧，懂的都懂）

[C语言程序](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/C_Fearless/)



# 2019年年末

## UNIX实验课shell程序：

1. [文本建立与键盘输入](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/UNIX_exp/unixtest01)

将用户从键盘输入的文本附加到一个指定的文件中。如果该文件不存在，则新建立该文件；如果该文件已经存在，则把键盘输入的文本附加到该文件后面。输入内容及行数不限定，以空行表示输入结束。运行结束时显示该文件内容。

2. [用户登录检测](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/UNIX_exp/unixtest02)

程序运行时首先列出当前系统中的已登录用户的名单，再检查指定用户是否已登录。如果已登录，则显示相应信息；如果未登录，则等待该用户登录，直到指定用户登录进入系统为止。

3. [文件状态查询](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/UNIX_exp/unixtest03)

动态检测指定文件的状态信息，当文件的大小发生改变时，给出提示信息，并继续前进检测。当文件的大小的变化次数或持续检查无变化次数达到一定值时，退出检查，程序结束。



# 2020年5月

## 操作系统实验课：

1. 哲学家就餐问题

在Unix系统下实现教材2.5.2节中所描述的哲学家就餐问题。5个哲学家，5根筷子。可以显示出每个哲学家的工作状态，如吃饭，思考。连续运行30次都未出现死锁现象。

[法一](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/OS_exp/OStest0101.c)

法一用了信号量和互斥量，避免了死锁，可以多个哲学家一起吃饭，但是不能两个哲学家同时拿筷子

[法二](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/OS_exp/OStest0102.c)

法二只用了互斥量，比法一更好。既避免了死锁，还可以多个哲学家同时拿筷子同时吃饭

2. [生产者/消费者问题](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/OS_exp/OStest02.c)

有一群生产者进程在生产产品，并将这些产品提供给消费者进程去消费。为使生产者进程与消费者进程能并发执行，在两者之间设置了一个具有10个缓冲区的缓冲池：生产者进程从文件中读取一个数据，并将它存放到一个缓冲区中；消费者进程从一个缓冲区中取走数据，并输出此数据。

生产者和消费者之间保持同步原则：不允许消费者进程到一个空缓冲区去取产品；也不允许生产者进程向一个已装满产品且尚未被取走的缓冲区中投放产品；不允许生产者和消费者同时对一个缓冲区下手。

3. [管道进程通信](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/OSexp/OS_test03.c)

在Linux系统中使用系统调用fork()创建两个子进程，使用系统调用pipe()建立一个管道，两个子进程分别向管道各写一句话：

   Child process 1 is sending a message!

   Child process 2 is sending a message!

而父进程则从管道中读出来自于两个子进程的信息，显示在屏幕上。然后分别结束两个子进程的运行。子进程1先写，子进程2后写，完了之后父进程才从管道读数据



# 2020年7月

## 计网编程实验：

TCP单进程循环服务器与单进程客户端：

这个是面向Echo服务的单进程循环服务器与单进程客户端

可以参考一个博客：[守望的个人博客](https://www.yanbinghu.com/categories/网络编程/)

[客户端源码](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Network_exp/1/tcp_echo_cli.c)

[服务器源码](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Network_exp/1/tcp_echo_srv.c)

## 实训-大数据：

我们小组是做一个b站大数据分析平台，我是负责处理数据的，用的都是python和spark

1. win pycharm版：

[represent_up_situ](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Spark_exp/pycharm/lex.py)（额这个稍微有点拉跨，因为这个是第一个写的，当时有点赶时间，就选了最粗糙最直接的办法，总之就是很简陋）

[area_click](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Spark_exp/pycharm/area_click.py)

[subarea_click](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Spark_exp/pycharm/subarea_click.py)

[top_up_subarea](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Spark_exp/pycharm/top_up_subarea.py)

[video_time_click](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Spark_exp/pycharm/video_time_click.py)

2. hdfs版：

本质上和pycharm版没有区别，只是为了在集群上跑得出来，做了些微调（另外那个拉跨的represent_up_situ我就不放了）

[area_click](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Spark_exp/hdfs/area_click.py)

[subarea_click](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Spark_exp/hdfs/subarea_click.py)

[top_up_subarea](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Spark_exp/hdfs/top_up_subarea.py)

[video_time_click](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Spark_exp/hdfs/video_time_click.py)



# 2020年10月

## 机器学习：

都是跟着Jack Cui的网站学习的。以下代码是我动手学习并改进成的适合我阅读的代码

1. k近邻算法：

[kNN_simplified](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/MachineLearning_learn/kNN/kNN_simplified.py)

[kNN_full](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/MachineLearning_learn/kNN/kNN_full.py)

[kNN_sklearn](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/MachineLearning_learn/kNN/kNN_sklearn.py)

2. 决策树：

[DecisionTree_step1](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/MachineLearning_learn/DecisionTree/DecisionTree_step1.py)

[DecisionTree_step2](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/MachineLearning_learn/DecisionTree/DecisionTree_step2.py)

[DecisionTree_sklearn](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/MachineLearning_learn/DecisionTree/DecisionTree_sklearn.py)

3. 朴素贝叶斯：

[NaiveBayes_simplified](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/MachineLearning_learn/NaiveBayes/NaiveBayes_simplified.py)

[NaiveBayes_full](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/MachineLearning_learn/NaiveBayes/NaiveBayes_full.py)

[NaiveBayes_sklearn](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/MachineLearning_learn/NaiveBayes/NaiveBayes_sklearn.py)



# 2020年11月

## flask：

这算是我给自己写的教学代码吧

把这一系列代码按顺序看完，基本上对flask就算是入门了（掺杂了一点点bootstrap）

[learn flask](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Flask_learn/)

## 算法：

跟着《算法图解》写代码练习。都是用python实现的

[learn algorithms in python](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Algorithms_Python/)

## 爬虫：

一点点爬虫，真的只有一点点。是爬小说的，用的requests

[getNovel](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Spider_learn/)

## 知识图谱：

用flask+py2neo+cytoscape.js实现的一个简易的知识图谱，所用数据为neo4j的官方示例

[practice KnowledgeGraph](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/KnowledgeGraph_practice/)

## leetcode：

开始刷leetcode了，具体每道题我就不写了，直接进文件夹看吧

注意，并不是我打了注释的每段方法都能通过leetcode，但理论上都是对的

[finish leetcode in C++](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Leetcode_C++/)

## 算法竞赛入门经典：

跟着《算法竞赛入门经典 第一版》写代码练习

[learn algorithms in c](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Algorithms_C/)



# 2020年12月

## html、css、js：

为找前端实习而重学前端，学习过程中为自己做的学习代码

[html](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Html_learn/)

[css](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/Css_learn/)

[js](https://github.com/wfJoanna/MyStudyRecords/blob/master/SchoolWork/JavaScript_learn/)