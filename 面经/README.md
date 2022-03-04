# Cpp-Experience
C++面经汇总，很多参考知乎，牛客，还有公众号，希望帮助大家

## 感想

**C++语法**

static，const，vector，map，new，malloc，面向对象，多态，虚函数，智能指针，右值引用

**数据结构与算法**

链表，二叉树，数组

**操作系统**

进程，进程通信，特点方式

**MySQL**



## 手撕算法

- 有序链表的合并
- 有序链表删除重复结点
- 二叉树求根结点到叶子的路径和为sum的路径
- 求二叉排序树第三大结点
- 旋转数组找最小值
- 很大数组中找第K大元素？
- 实现有序二叉树的插入方法？(手撕)
- 10亿行32位无符号整数，找出第7亿大的数是多少？只给300M内存？
- 分解质因数？(手撕)
- 500个数组，每个数组有500个元素，从大到小排序好，找出前500个最大的数？
- 写一个环形缓冲区吧(手撕)？
- 斐波那契数列第n项?分析递归算法复杂度?有没有比O(n)更快的算法？快速幂怎么算？
- 链表第m到第n个反转
- 一个n位数，现在可以删除其中任意k位，使得剩下的数最小(前导零忽略)？
- 实现有符号大数链表加法，靠近头结点位置为高位。
- 手撕快排？
- 并查集的并的操作和查的操作？(手撕)

## 数据结构

- 常见的hash算法？
- 一致性哈希如何优化？
- 写个shared_ptr的实现？(手撕)
- 求二叉树中序遍历的后继结点。
- 常见的排序算法和时间复杂度？介绍归并排序的思想？介绍堆排序思想？
- 红黑树？
- 哈希冲突的处理方法？
- 怎么求无向图的连通块？

## C++语法

- static关键字用法
- 为什么要有虚析构函数
- const有哪几种用法？常成员函数？mutable？
- 重载和重写？
- STL了解吗？
- 智能指针？
- 简单说一下C++的多态？运行期的多态有什么好处？
- A、B、C链式继承，问最后一共有多少个虚函数表？
- 构造函数可以是虚函数吗？析构函数可以是虚函数吗？
- C++异常了解吗？发生异常语言层会做些什么样的事？
- STL用的多吗？说一下常用容器？map怎么实现的？
- malloc与new的区别？
- new分配的内存是虚拟内存还是物理内存？
- 一个类定义很多set(key,value)方法，其中value的类型可能是int、double、string等等(会动态增加，要求考虑可扩展性)，同时提供对应的get(key)方法，要求给出内部实现，不能在类里面直接定义int、double、string等类成员变量(这里面扩展出了继承、多态、auto、C++类型转换等知识点)。
- 定义一个类T，使得vector<T>和T a[10]这两个定义，一个成功，一个失败。
- 虚函数怎么实现的？
- 面向对象的多态指的是什么？
- 指针常量&常量指针？
- 常量函数？
- 函数参数：const int& x VS int x？
- 内存泄漏？什么情况容易出现内存泄漏？如何避免内存泄漏？
- 浅拷贝与深拷贝？
- 右值应用？string什么时候发生右值引用？
- C++11的新标准有了解哪些？
- 声明和定义是什么意思？
- 指针函数和函数指针是什么意思？
- strcpy的问题？
- 野指针了解吗？
- STL源码？vector?
- vector跟list的区别？
- vector底层占用内存空间是连续的吗？扩容机制？
- 类的大小由哪些因素影响？内存对齐？类成员函数会影响对象大小吗？
- 内存越界？内存溢出？

## 操作系统

- 进程间通信，各自什么特点？什么应用场景？
- 如何维持线程安全
- 某进程创建了若干线程，这些线程不能共享的是？
- 进程和线程的区别？线程池？
- 什么时候用进程什么时候用线程？
- 操作系统了解多吗？为什么分用户态和核心态？
- 协程了解吗？
- 假设一个线程sleep睡个十秒，这是怎么样的一个进程调度？
- 虚拟内存机制？
- LRU页面置换算法(手撕)
- 一个进程的内存空间具体是怎么分的？堆与栈的区别？数据结构里面栈与队列的区别？在操作系统里面的栈为什么要保证它后进先出？
- 死锁的必要条件？
- 银行家算法？
- 乐观锁与悲观锁？
- 操作系统，mmu解释一下，什么是快表，为什么快？
- 

## 计算机网络

- 滑动窗口是用来干什么的？
- soket调用接口？
- 网络库有用过哪些？
- IP层如何找MAC地址？如果对应IP不在局域网呢?
- 网桥？虚拟设备对？
- ARP攻击，ARP欺骗？
- 三次握手？
- UDP数据包长度多少？
- 进程的状态有几种？
- http头部方法GET?POST?其他的有了解吗？GET和POST的区别？POST可以在URL中携带参数吗？
- cookie有存什么东西吗？
- 五层网络模型? 交换机那一层？路由器呢？路由器干嘛的？
- TCP为啥可靠？
- 网络编程有接触过吗？socket read？socket write?read&write的缓冲区与TCP滑动窗口中的缓冲区是什么关系？
- 有接触过IO多路复用这个概念吗？epoll有几种触发方式？怎样的场景会用怎样的触发方式？
- TCP断开连接是几次挥手？为什么？
- 介于TCP与UDP两者之间的一些协议了解吗？
- TCP断开连接的过程说一下？中间分别处于什么状态？
- http的报文结构？http方法有哪些？PUT和POST的区别？
- TCP面向连接，面向字节流，你怎么理解这句话？
- 计算机网络七层结构？每一层主要做什么？http、tcp分别属于哪一层？
- http的状态码有哪些?
- http与https的区别？https的加密方式？
- 两台机子互ping的过程？

## Linux

- Linux静态库和动态库有什么区别？动态库的加载器是哪个？
- glibc是干什么的？
- Linux常见的信号有哪些？
- kill -9？进程组？Group ID和PPID什么区别？
- 对Linux环境的了解？
- Linux? ps? grep? 强行杀掉某个进程要怎么做?
- 有没有了解链接？动态链接中什么是共享？什么不是共享的？动态库中有一些全局变量怎么办？全局变量是一份吗？一份不就互相冲突了吗？
- 写一个程序，使它编译成功，链接失败？
- Linux操作系统有用过吗？TOP指令？buffer内存？free内存？
- 管道是什么意思？进程间通信的方法有哪些？socket怎么用？本机用socket怎么做进程通信？本机监听哪个IP?

## 参考

- [秋招｜C++面经合集（腾讯、百度、滴滴、网易互娱、字节跳动、猿辅导等14家面经） - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/91838785)
- [笔经面经 - 知乎 (zhihu.com)](https://www.zhihu.com/column/b-jing-m-jing)
- [(155条消息) 超全面的后端开发C/C++面经整理分享含详细参考答案 包括简历分享_GhostLWB的博客-CSDN博客](https://blog.csdn.net/neverever01/article/details/108237531?ops_request_misc=%7B%22request%5Fid%22%3A%22163757445216780264076530%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=163757445216780264076530&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-108237531.pc_search_result_control_group&utm_term=C%2B%2B面经&spm=1018.2226.3001.4187)
- [(155条消息) 【实习秋招篇之C++面经】_Joker_N的博客-CSDN博客](https://blog.csdn.net/Joker_N/article/details/108324880?ops_request_misc=%7B%22request%5Fid%22%3A%22163757445216780264076530%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=163757445216780264076530&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-2-108324880.pc_search_result_control_group&utm_term=C%2B%2B面经)
- [(155条消息) C++面经大全_古月潇雨-CSDN博客_c++面经](https://blog.csdn.net/qq_18539301/article/details/82999429?ops_request_misc=&request_id=&biz_id=102&utm_term=C++面经&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-1-82999429.pc_search_result_control_group&spm=1018.2226.3001.4187)
- [(157条消息) 腾讯2018日常实习一面（电话面试）_dazhongshuo1167的博客-CSDN博客](https://blog.csdn.net/dazhongshuo1167/article/details/101351366?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~default-2.no_search_link&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~default-2.no_search_link)
- [(157条消息) 腾讯后台开发日常实习面经_landness的博客-CSDN博客](https://blog.csdn.net/weixin_44409077/article/details/108306721?ops_request_misc=%7B%22request%5Fid%22%3A%22163791718716780264040363%22%2C%22scm%22%3A%2220140713.130102334.pc%5Fall.%22%7D&request_id=163791718716780264040363&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-108306721.pc_search_result_control_group&utm_term=C%2B%2B后端日常实习面经&spm=1018.2226.3001.4187)
- [(157条消息) 腾讯C++后台开发实习面经（已拿offer）_互联网校招面经-CSDN博客](https://blog.csdn.net/m0_48634217/article/details/106759266)
- 

