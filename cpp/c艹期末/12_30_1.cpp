#include<iostream>
using namespace std;
template <class T>
struct Node
{
	Node* next;
	T value;
	int index;
};
template <class T>
class List1
{
	Node<T> *pFirst;
	T *list;
	int length,arraysize;
	public:
		void Insert(int n,T value);
		void Remove(int index); 
		void print();
	//	void expand();
		Node<T>* Find(int n);
		List1(int n,T* t);
 };
template <class T>
List1<T>::List1(int n,T* t)
{
	list=new T[100];
	length=0;
	for(int i=0;i<100;i++)
	list[i]=-1;
	pFirst=NULL;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			pFirst=new Node<T>;
			pFirst->value=t[i];
			pFirst->next=NULL;
		}
		else
		{
			Node<T> *p=new Node<T>;
			p->value=t[0];
			p->next=pFirst;
			pFirst=p; 
		}
		list[i]=t[i];
		length++;
	}
}/*
template <class T>

void List1<T>::expand()//令数组元素个数不能少于数组长度1/2 
{
	if(length>=arraysize/2)
	arraysize*=2;
	T* newlist=new T[arraysize];
	for(int i=0;i<length;i++)
	newlist[i]=list[i];
	for(int i=length;i<arraysize;i++)
	newlist[i]=-1;
	delete[] list;
	list=newlist;
}
*/
template <class T>
Node<T>* List1<T>::Find(int n)
{
	Node<T> *p;
	for(p=pFirst;p->index!=n-1;p=p->next);//前一位 
	return p;
}
template <class T>
void List1<T>::Insert(int n,T value)
{
	Node<T> *p=new Node<T>;
	p->value=value;
	Node<T> *pivot=Find(n);
	p->next=pivot->next->next;
	pivot->next=p;
	
	length++;
	//expand();
	pFirst=p;
	//更新数组 
	int i=0; 
	for(Node<T> *p1=pFirst;p1!=NULL;p1=p1->next)
	{
		list[i++]=p1->value;
	}
	
}
template <class T>
void List1<T>::Remove(int n)
{
	Node<T> *p=Find(n);
	p->next=p->next->next;
	Node<T> *dp=p;
	delete dp;
	length--;
	//未实现缩小数组 
	int i=0; 
	for(Node<T> *p1=pFirst;p1!=NULL;p1=p1->next)
	{
		list[i]=p1->value;
	}
}
template <class T>
void List1<T>::print()
{
	for(int i=0;i<length;i++)
	{
		cout<<list[i]<<" "<<endl;
	}
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int addindex,addvalue,removeindex;
	cin>>addindex>>addvalue>>removeindex;
	List1<int> l(n,a);
	l.Insert(addindex,addvalue);
	l.Remove(removeindex);
	l.print();
	cin>>n;
	float *b=new float[n];
	for(int i=0;i<n;i++)
	cin>>b[i];
	List1<float> f(n,b);
	f.Insert(addindex,addvalue);
	f.Remove(removeindex);
	f.print();
}
