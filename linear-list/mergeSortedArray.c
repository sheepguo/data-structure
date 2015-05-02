//有两个顺序表示的线性表，都是升序排列，将这两个线性表合并成一个，按升序排列
//算法一：先不管顺序进行合并，再进行排序；
//算法二：两个线性表为LA和LB，设两个指针i和j分别指向LA和LB中的元素，如i当前指向的元素是a，j当前指向的元素是b，则应当插入到LC中的元素c为
//c	=  a,  当a<=b时
//c	=  b,  当a>b时

//明显算法二的时间复杂度更低，为O(lenA+lenB),其中lenA、lenB分别是LA和LB的长度
//本函数实现算法二

//如何命名，才能最好的体现出函数的作用
//如何才能让该函数适用于各种类型的数组
//free()函数能够清理多大的数组

#include <stdio.h>
#include <stdlib.h>

struct array{
	int* starter;	//数组起始指针
	int  len;		//数组长度
};


//LA和LB为需要合并的两个数组，LC为合并之后的数组
struct array mergeSortedArray(int* LA, int lenA, int* LB, int lenB)
{
	int i,j;
	struct array mergedArray;
	mergedArray.len = lenA+lenB;
	mergedArray.starter = malloc(mergedArray.len*sizeof(int));	//给LC分配长度为(lenA+lenB)*sizeof(int)的内存空间

	if (mergedArray.starter == '\0') {printf("动态分配数组地址失败\n");	return mergedArray;}
	for(i=0,j=0;i<lenA&&j<lenB;)
	{
		if(*(LA+i)<=*(LB+j))	//如果LA中的数小，就把LA中的数放入LC中 
		{
			*(mergedArray.starter+i+j) = *(LA+i);
			i++;
		}
		else					//如果LB中的数小，就把LB中的数放入LC中
		{
			*(mergedArray.starter+i+j) = *(LB+j);
			j++;
		}
	}
	while(i<lenA) { *(mergedArray.starter+i+j) = *(LA+i); i++;}
	while(j<lenB) {	*(mergedArray.starter+i+j) = *(LB+j); j++;}
	return mergedArray;	
}


//测试程序
void main()
{
	int LA[5]={1,2,3,4,5};
	int LB[5]={1,7,8,9,10};
	struct array mergedArray;
	mergedArray = mergeSortedArray(LA,5,LB,5);
	int i;
	for(i=0;i<mergedArray.len;i++) printf("%d  ",mergedArray.starter[i]);
	printf("\n");
}
