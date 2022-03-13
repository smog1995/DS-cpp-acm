#include <iostream>
#include <string>
using namespace std;
class HuffNode{
	public:
		int weight;
		int parent;
		int leftchild;
		int rightchild;
};
class HuffMan{
	private:
		void MakeTree()
		{
			int i,s1,s2;
			for(int lnum+1;i<=len;i++)
			{
				SelectMin(i-1,&s1,&s2);
				huffTree[s1].parent=huffTree[s2].parent=i;
				huffTree[i].lc=s1;
				huffTree[i].rc=s2;
				huffTree[i].weight=huffTree[s1].weight+huffTree[s2].weight;
			}
		}
		void SelectMin(int pos,int* s1,int* s2);
	public:
		int len;
		int lnum;
		HuffNode* huffTree;
		string *huffCode;
		void MakeTree(int n,int wt[]);
		void Coding();
		void Destroy();
};
void Coding()
{
	
	for(int i=1;i<=lnum;i++)
	{
		string *ass=new string(lnum);//����������н������һ�߼�lnum�� 
		int start=lnum-1;
		for(int c=i,f=huffTree[i].parent;f!=0;c=f,f=huffTree[i].parent)
		{
			if(huffTree[f].leftchild==c) ass[start--]='0';
			else ass[start--]='1';
		}
		huffCode[i]=ass;
		delete ass;
	}
}
void huffMan::SelectMin(int pos,int *s1,int* s2)
{
	int w1=w2=99999,i=0;
	for(int i=1;i<pos;i++)
	{
		if(huffTree[i].weight<w1)
		{
			w2=w1;
			*s2=*s1;
			*s1=i;
			w1=huffTree[i].weight;
		}
		else if(huffTree[i].weight<w2)
		{
			w2=huffTree[i].weight;
			*s2=i;
		}
	}
} 
void HuffMan::MakeTree(int n,int wt[])
{
	int i;
	lnum=n;
	len=2*n-1;//n���������ɽ������Ϊ2*n-1�Ĺ������� 
	huffTree=new HuffNode[2*n];//��0�Ų���� 
	huffCode=new string[lnum+1];//��0�Ų����,�� 
	//huffCodeʵ�����Ǹ���ά���飬��i�б�ʾ��i���ַ���Ӧ�ı���
	//�շ������ʼ��
	for(int i=1;i<=n;i++)
	huffTree[i].weight=wt[i-1];
	for(int i=1;i<=len;i++)
	{
		if(i>n) huffTree[i].weight=0;
		huffTree[i].parent=0;
		huffTree[i].leftchild=0;
		huffTree[i].rightchild=0;
	}
	MakeTree();
	
}
int main()
{
	
 } 
