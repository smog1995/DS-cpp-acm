#include<iostream>
using namespace std;
#define MAX_TREE_SIZE 100
//���Ĵ洢�ṹ֮˫�׷�ʵ��һ���ṹ��ʵ��
typedef struct
{
	ElemType data;//����Ԫ��
	int parent;//˫��λ����
}PTNode;
typedef struct//�����Ͷ���
{
	PTNode nodes[MAX_TREE_SIZE];//˫�ױ�ʾ
	int n;//�ڵ���
}PTree;

//����ʵ��
element_type value[MAX_TREE_SIZE];
int parent[MAX_TREE_SIZE];
element_type* parent[MAX_TREE_SIZE];//���ڵ��ַ
int n;//�������

//��
