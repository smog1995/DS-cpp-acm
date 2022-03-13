#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100 //�������Ա�Ĵ洢�ռ�Ĵ�С
#define OVERFLOW -2
#define OK 1
#define ERROR 0
int e, i, j, n, q;     //ȫ�ֱ���
//����һ��˳�����Ա�
// =======�ǳ���Ҫ��Ҫ������Ա�Ľṹ�����Ա��ڰ����� ���� �� ���Ա�ĳ��� �� ���Ա�洢����========================
//1.�������Ա�Ľṹ��
typedef struct {
	int* elem; //�洢�ռ����ַ��elem��һ��������������ָ�룬ָ������������ָ�룬��������Ԫ�ص�ַ��ָ�롣����ָ�������ָ�롣
	int listsize; //���Ա�洢����
	int length; //��ǰ���Ա�ĳ���
}SqList;
//2.�������Ա�ĺ���
//����һ�����Ա��˳�����Ա�ĳ�ʼ������
int InitList_Sq(SqList& L) {
	L.elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));//��̬���� "����" �Ŀռ䣺����100*4�ֽڵĿռ䲢��Ϊ100��4�ֽڵ�С�ռ������elem��
	if (!L.elem) {
		exit(OVERFLOW);  //�洢�ռ����ʧ�ܣ��������(-2)
	}
	L.length = 0;//��ǰ�ձ������ݣ�����Ϊ0��
	L.listsize = LIST_INIT_SIZE;//��ǰ���Ա�ĳ�ʼ�洢����
	return OK;
}//
//3.˳�����Ա�Ĳ��뺯��
//�ڵ�i��Ԫ��֮ǰ������Ԫ��e
//i�ĺϷ�ֵΪ1<=i<=L.length+1
int ListInsert_Sq(SqList& L, int i, int e) {
	printf("\n������Ҫ�����Ԫ�أ�");
	scanf("%d", &e);
	printf("\n������Ҫ�����λ�ã�");
	scanf("%d", &i);
	if (i <1 || i > L.length + 1) {//i��ȡֵ���Ϸ�
		printf("�����i����ֵ���Ϸ�");
		return ERROR;
	}
	if (L.length == L.listsize) {//���Ա�ĳ��ȵ������Ա�Ĵ洢������˵���洢�ռ����������Բ��Ϸ�
		return ERROR;
	}
	for (int j = L.length; j > i - 1; j--) {//�Ѳ���λ�ú�֮���Ԫ��λ�ú���
		L.elem[j] = L.elem[j - 1];
	}
	L.elem[i - 1] = e;//����Ԫ��e����
	L.length++;//����һ
	printf("\n������Ԫ��%d", e);
	printf("�Ժ������Ϊ:");
	for (i = 0; i < n + 1; i++) {
		printf("%d\t", L.elem[i]);
	}
	return OK;
}
int main() {
	SqList L;
	InitList_Sq(L);
	printf("\n����������ĳ��ȣ�");
	scanf("%d", &n);
	printf("\n�����������Ԫ�أ�");
	for (i = 0; i < n; i++) {
		scanf("%d", &q);
		L.elem[i] = q;
		++L.length;
	}//��������
	printf("\n����Ϊ��");
	//��������
	for (i = 0; i < n; i++) {
		printf("%d", L.elem[i]);
	}
	ListInsert_Sq(L, i, e);
	return 0;
}