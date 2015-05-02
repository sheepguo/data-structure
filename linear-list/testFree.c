/*
	这个函数的作用是，验证free()函数的用法
	尚且不清楚free()函数的实现原理，有两点出发点需要弄明白
	1. Linux系统内存管理的机制;
	2. C函数中如何一步一步单步调试，跟进到库函数，甚至是系统调用函数中
*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int* LA = 	malloc(12);
	*LA 	=	1;
	*(LA+1*sizeof(int))	=	2;
	*(LA+2*sizeof(int))	=	3;
	*(LA+3*sizeof(int))	=	4;
	*(LA+4*sizeof(int))	=	5;
	int* pointer	=	0;
	for(pointer=LA;pointer<=LA+4*sizeof(int);pointer=pointer+sizeof(int))
		printf("%d ",*pointer);
	printf("\n");
	//free(LA+sizeof(int));	//无法实现
	pointer = LA;
	free(pointer);
	for(pointer=LA;pointer<=LA+4*sizeof(int);pointer=pointer+sizeof(int))
		printf("%d ",*pointer);
	printf("\n");	

/*	
	不可以从非分配内存的起始进行内存的销毁
	猜测：销毁内存是需要调用操作系统的系统函数的，而所有内存的使用情况在系统中有明确的管理
*/
}
