/*
	该函数的作用，用来验证C语言中关于初始化、数组的一些操作，具体如下：
	1.如何求数组长度
	2.int和char变量，如果不初始化会如何
	3.int型和char型数组的定义和初始化
	4.string的操作

	author:guozheng
	2015/05/02
*/




#include <stdio.h>


void main()
{
/*
	在C语言中，求数组长度的几种方法
	方法一，对于数组array，Len=sizeof(array)/sizeof(array[0])
	方法二，对于数组array，是否存在最后一位是'\0'呢？
	int型数组和char型数组是否有区别？
*/
	int array1[]= 	{ 1,2,3};
	int array2[]= 	{ 5,6,7,8};

	int len1 	=	sizeof(array1)/sizeof(array1[0]);
	int len2 	=	sizeof(array2)/sizeof(array2[0]);

	printf("len1=%d,len2=%d\n",len1,len2);
	//输出结果正确，即方法一可行
	
	int i		=	0;
	for (i=0;i<10;i++) printf("%d ",*(array1+i));
	printf("\n");
	//输出结果为：1 2 3 3 3 4 134513888 0 0 -1218931501，即不存在数组的最后一位是标志位，也就是说，我们无法事后知道数组的长度
	
/*
	初始化int和char
*/
	int a;
	printf("未初始化的int=%d\n",a);
	char c  ;
	printf("未初始化的char=%c\n",c);
	printf("\n");
	printf("未初始化的char=%d\n",c);
/*
	输出为：
	未初始化的int=134513961
	未初始化的char=
	未初始化的char=-73
	
	可见在C语言中，所有的一切初始化都是需要我们自己做的，并且由于char对应的未初始化值是负数，导致在输出字符的时候出现问题
*/


/*
	int 型数组定义的几种方式
*/
	int arr1[5]	=	{1,2,3,4,5};
	int arr2[5]	=	{1,2,3};
	//int arr3[5]	=	0;			//不行
	int arr4[]	=	{1,2,3,4,5};
	int arr5[10]=	{0};			//将数组初始化0的好方法
	for(i=0;i<10;i++) printf("%d ",arr2[i]); printf("\n");
	for(i=0;i<10;i++) printf("%d ",arr5[i]); printf("\n");

/*
	用指针定义int型数组
*/

	int* point2 = 0;
	int* point3 = NULL;
	//int* point4 = 11;	// warning: initialization makes pointer from integer without a cast [enabled by default]
	int hey = 1;
	int* point1 = &hey;
	*point1=0;
	point1[1]=1;
	point1[2]=2;
	for(i=0;i<10;i++) printf("%d ",point1[i]); printf("\n");

/*
	初始化指针的几种方式:
	1. int* pointer = 0;//指向空地址
	2. int* pointer = NULL;//同上
	3. int a;  int* pointer = &a;
	4. int* pointer = 11;//这种方式是不行的，因为系统是不会允许我们将指针指向任意一个内存空间的，会产生编译错误
	
	如上对于point1的操作，其实是很危险的，因为point1+1*sizeof(int)指向的内存空间有可能是被使用的，而我这样的用法会将其改变

	因此，如果要用指针的方式创建数组，就需要先分配相应的内存地址，而不要去干扰别人家的地盘
*/

/*
	char型数组的初始化
*/
	char arrayChar1[5]	= 	{'a','b','c','d','e'};
	char arrayChar2[]	=	{'a','b','c','d','e'};
	char arrayChar3[5]	=	{'a'};
	char arrayChar4[5]	=	"abc";
	char arrayChar5[5];
	char arrayChar6[5];
	char arrayChar7[]	=	"abc";

	printf("arrayChar1中的数组：");
	for(i=0;i<10;i++) printf("%d ",arrayChar1[i]); printf("\n");
	printf("arrayChar2中的数组：");
	for(i=0;i<10;i++) printf("%d ",arrayChar2[i]); printf("\n");
	printf("arrayChar3中的数组：");
	for(i=0;i<10;i++) printf("%d ",arrayChar3[i]); printf("\n");
	printf("arrayChar4中的数组：");
	for(i=0;i<10;i++) printf("%d ",arrayChar4[i]); printf("\n");
	printf("arrayChar5中的数组：");
	for(i=0;i<10;i++) printf("%d ",arrayChar5[i]); printf("\n");
	printf("arrayChar6中的数组：");
	for(i=0;i<10;i++) printf("%d ",arrayChar6[i]); printf("\n");
	printf("arrayChar7中的数组：");
	for(i=0;i<10;i++) printf("%d ",arrayChar7[i]); printf("\n");

	printf("arrayChar1中的数组长度：");
	printf("%d\n",sizeof(arrayChar1)); 
	printf("arrayChar2中的数组长度：");
	printf("%d\n",sizeof(arrayChar2)); 
	printf("arrayChar3中的数组长度：");
	printf("%d\n",sizeof(arrayChar3)); 
	printf("arrayChar4中的数组长度：");
	printf("%d\n",sizeof(arrayChar4)); 
	printf("arrayChar5中的数组长度：");
	printf("%d\n",sizeof(arrayChar5)); 
	printf("arrayChar6中的数组长度：");
	printf("%d\n",sizeof(arrayChar6)); 
	printf("arrayChar7中的数组长度：");
	printf("%d\n",sizeof(arrayChar7)); 

	arrayChar2[1]='z';
	arrayChar4[1]='z';

/*
	初始化的几种方法:
	1. char a[5] = {'a','b'};	//没有初始化的位会以'\0'补上
	2. char a[5] = "abc";		//作用同上
	3. char a[]	 = {'a','b'};
	4. char a[]  = "abc";

	不管是int型的数组，还是char型的数组，都需要初始化，并且对于没有初始化的位，都用0进行补充
*/

/*
	C语言中的string
*/
	printf("以string形式输出字符串数组\n");
	printf("arrayChar3是:%s\n",arrayChar3);
	printf("arrayChar4是:%s\n",arrayChar4);
	printf("arrayChar7是:%s\n",arrayChar7);

	char* string1 = "abcde";
	printf("string1是：%s\n",string1);
	printf("string1[1]是%d\n",string1[1]);
	//string1[1] = 100;	//"abcde"是常量，不能更改

	char* string2 = arrayChar4;
	string2[2] = 100;
	printf("string2是：%s\n",string2);
	printf("现在的arrayChar3是:%s\n",arrayChar4);

/*
	char* 的赋值有两种方式
	1. 用常量赋值给char*, 如 char* a = "abc"；这样的话，不能更改a中的值；
	2. 用一个内存赋值给char*，如 char array[5] = "abc";	char* a	= &array; 这样的话，可以更爱a中的值，响应的也就改了array的值。不过我觉着这样的转换是没有必要的，不实用的
*/
}
