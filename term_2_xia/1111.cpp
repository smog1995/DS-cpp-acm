#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100 //定义线性表的存储空间的大小
#define OVERFLOW -2
#define OK 1
#define ERROR 0
int e, i, j, n, q;     //全局变量
//建立一个顺序线性表
// =======非常重要：要理解线性表的结构，线性表内包含了 数组 和 线性表的长度 和 线性表存储容量========================
//1.定义线性表的结构体
typedef struct {
	int* elem; //存储空间基地址。elem是一个数组名。数组指针，指的是数组名的指针，即数组首元素地址的指针。即是指向数组的指针。
	int listsize; //线性表存储容量
	int length; //当前线性表的长度
}SqList;
//2.构造线性表的函数
//构造一个线性表和顺序线性表的初始化操作
int InitList_Sq(SqList& L) {
	L.elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));//动态分配 "数组" 的空间：开辟100*4字节的空间并分为100个4字节的小空间给数组elem。
	if (!L.elem) {
		exit(OVERFLOW);  //存储空间分配失败，返回溢出(-2)
	}
	L.length = 0;//当前空表无内容，长度为0。
	L.listsize = LIST_INIT_SIZE;//当前线性表的初始存储容量
	return OK;
}//
//3.顺序线性表的插入函数
//在第i个元素之前插入新元素e
//i的合法值为1<=i<=L.length+1
int ListInsert_Sq(SqList& L, int i, int e) {
	printf("\n请输入要插入的元素：");
	scanf("%d", &e);
	printf("\n请输入要插入的位置：");
	scanf("%d", &i);
	if (i <1 || i > L.length + 1) {//i的取值不合法
		printf("输入的i的数值不合法");
		return ERROR;
	}
	if (L.length == L.listsize) {//线性表的长度等于线性表的存储容量，说明存储空间已满，所以不合法
		return ERROR;
	}
	for (int j = L.length; j > i - 1; j--) {//把插入位置和之后的元素位置后移
		L.elem[j] = L.elem[j - 1];
	}
	L.elem[i - 1] = e;//将新元素e插入
	L.length++;//表长加一
	printf("\n插入新元素%d", e);
	printf("以后的数组为:");
	for (i = 0; i < n + 1; i++) {
		printf("%d\t", L.elem[i]);
	}
	return OK;
}
int main() {
	SqList L;
	InitList_Sq(L);
	printf("\n请输入数组的长度：");
	scanf("%d", &n);
	printf("\n请输入数组的元素：");
	for (i = 0; i < n; i++) {
		scanf("%d", &q);
		L.elem[i] = q;
		++L.length;
	}//输入数组
	printf("\n数组为：");
	//遍历数组
	for (i = 0; i < n; i++) {
		printf("%d", L.elem[i]);
	}
	ListInsert_Sq(L, i, e);
	return 0;
}