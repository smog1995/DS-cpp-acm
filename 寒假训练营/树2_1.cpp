#include<iostream>
using namespace std;
#define MAX_TREE_SIZE 100
//树的存储结构之双亲法实现一：结构体实现
typedef struct
{
	ElemType data;//数据元素
	int parent;//双亲位置域
}PTNode;
typedef struct//树类型定义
{
	PTNode nodes[MAX_TREE_SIZE];//双亲表示
	int n;//节点数
}PTree;

//数组实现
element_type value[MAX_TREE_SIZE];
int parent[MAX_TREE_SIZE];
element_type* parent[MAX_TREE_SIZE];//父节点地址
int n;//结点数量

//树
