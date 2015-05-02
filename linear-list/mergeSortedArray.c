//有两个顺序表示的线性表，都是升序排列，将这两个线性表合并成一个，按升序排列
//算法一：先不管顺序进行合并，再进行排序；
//算法二：两个线性表为LA和LB，设两个指针i和j分别指向LA和LB中的元素，如i当前指向的元素是a，j当前指向的元素是b，则应当插入到LC中的元素c为
//c	=  a,  当a<=b时
//c	=  b,  当a>b时

//明显算法二的时间复杂度更低，为O(lenA+lenB),其中lenA、lenB分别是LA和LB的长度


//如何命名，才能最好的体现出函数的作用
//如何才能让该函数适用于各种类型的数组
//free()函数能够清理多大的数组

#include <stdio.h>
#include <stdlib.h>

//LA和LB为需要合并的两个数组，LC为合并之后的数组
void mergeSortedArray(int* LA, int* LB, int* LC)
{
	int lenA,lenB;
	int i,j;
	printf("int 类型的初始值为%d\n",lenA);
	for(i=0;i<20;i++)printf("%d ",LA[i]); printf("\n");
	
	
	lenA = 0;
	lenB = 0;
	while (*(LA+lenA*sizeof(int))!='\0') lenA++;
	while (*(LB+lenB*sizeof(int))!='\0') lenB++;	//算到的lenA是LA的绝对长度，即{1,2,3}对应的len为3
	printf("lenA=%d,lenB=%d\n",lenA,lenB);	
	lenA = 0;
	lenB = 0;
	while (LA[lenA]!='\0') lenA++;
	while (LB[lenB]!='\0') lenB++;	//算到的lenA是LA的绝对长度，即{1,2,3}对应的len为3
	printf("lenA=%d,lenB=%d\n",lenA,lenB);	
	
	
	LC = (int*) malloc((lenA+lenB)*sizeof(int));	//给LC分配长度为(lenA+lenB)*sizeof(int)的内存空间
	if (LC == '\0') {printf("动态分配数组地址失败\n");	return;}
	
	for(i=0,j=0;i<lenA&&j<lenB;)
	{
		if(*(LA+i)<=*(LB+j))	//如果LA中的数小，就把LA中的数放入LC中 
		{
			*(LC+i+j) = *(LA+i);
			i++;
		}
		else					//如果LB中的数小，就把LB中的数放入LC中
		{
			*(LC+i+j) = *(LB+j);
			j++;
		}
	}
	printf("i=%d,j=%d\n",i,j);
	while(i<lenA) { *(LC+i+j) = *(LA+i); i++;}
	while(j<lenB) {	*(LC+i+j) = *(LB+j); j++;}
	for(i=0;i<10;i++) printf("%d  ",LC[i]);
	printf("\n");
}


//测试程序
void main()
{
	int LA[5]={1,2,3,4,5};
	int LB[5]={1,7,8,9,10};
	int* LC;
	mergeSortedArray(LA,LB,LC);
	int i;
	for(i=0;i<10;i++) printf("%d  ",LC[i]);
	printf("\n");
}
