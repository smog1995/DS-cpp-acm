#include <iostream>
using namespace std;
template <class T>
class List1
{
	T* t;
	int length;
public:
	List1(int n, T* t1);
	void remove(int idx);
	void add(int idx, T v);
	void print();
};
template <class T>
List1<T>::List1(int n, T* t1)
{
	t = new T[100];
	length = n;
	for (int i = 0; i < 100; i++)
		t[i] = -1;
	for (int i = 0; i < 5; i++)
	{
		t[i] = t1[i];
	}
}
template <class T>
void List1<T>::add(int index, T v)
{
	length++;
	T *newList = new T[100];
	for (int i = 0; i < 100; i++)
		newList[i] = -1;
	for (int i = 0; i <index; i++)
		newList[i] = t[i];
	newList[index] = v;
	for (int i = index + 1; i < length; i++)
		newList[i] = t[i-1];
	delete[] t;
	t = newList;
	
}
template <class T>
void List1<T>::remove(int idx)
{
	length--;
	T *newList = new T[100];
	for (int i = 0; i < 100; i++)
		newList[i] = -1;
	for (int i = 0; i < idx; i++)
	{
		 newList[i] = t[i];
	}
	for (int i = idx; i < length; i++)
	{
		newList[i] = t[i+1];
	}
	delete[] t;
	t = newList;
	
}
template <class T>
void List1<T>::print()
{
	for (int i = 0; i < length; i++)
		cout << t[i] << " ";
	cout << endl;
}
int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i]; 
	int addindex, addvalue, removeindex;
	cin >> addindex >> addvalue >> removeindex;
	List1<int> l(n, a);
	l.add(addindex, addvalue);
	l.remove(removeindex);
	l.print();
	cin >> n;
	float *b = new float[n];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	int addindex1, removeindex1;
	float addvalue1;
	cin >> addindex1 >> addvalue1 >> removeindex1;
	List1<float> f(n, b);
	f.add(addindex1, addvalue1);
	f.remove(removeindex1);
	f.print();
}