用来指出linear-list路径中各个文件的作用

lenOfArray.c
	该函数的作用，用来验证C语言中关于初始化、数组的一些操作，具体如下：
	1.如何求数组长度
	2.int和char变量，如果不初始化会如何
	3.int型和char型数组的定义和初始化
	4.string的操作
	2015/05/02

testFree.c
    这个函数的作用是，验证free()函数的用法
    尚且不清楚free()函数的实现原理，有两点出发点需要弄明白
    1. Linux系统内存管理的机制;
    2. C函数中如何一步一步单步调试，跟进到库函数，甚至是系统调用函数中
	2015/05/02
	
mergeSortedArray.c
	有两个顺序表示的线性表，都是升序排列，将这两个线性表合并成一个，按升序排列
	算法一：先不管顺序进行合并，再进行排序；
	算法二：两个线性表为LA和LB，设两个指针i和j分别指向LA和LB中的元素，如i当前指向的元素是a，j当前指向的元素是b，则应当插入到LC中的元素c为
	c =  a,  当a<=b时
	c =  b,  当a>b时
	明显算法二的时间复杂度更低，为O(lenA+lenB),其中lenA、lenB分别是LA和LB的长度
	本函数实现算法二
	2015/05/02

ArrayListExamples.java
	使用ArrayList这个类的各种方法
	来自：http://examples.javacodegeeks.com/core-java/util/arraylist/arraylist-in-java-example-how-to-use-arraylist/
	2015/05/02

LinkedListExample.java
	使用LinkedList这个类的各种方法
	来自：http://examples.javacodegeeks.com/core-java/util/linkedlist/java-linkedlist-example/
	2015/05/02





