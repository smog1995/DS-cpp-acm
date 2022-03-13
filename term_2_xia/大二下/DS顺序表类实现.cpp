#include <iostream>
#include <cstdlib>
using namespace std;
#define ok 0
#define error -1
void input(int* L,int n)
{
	for (int i = 0; i < n; i++)
		cin >> L[i];
}
class SeqList
{
private:
	int *list;
	int maxsize;
	int size;
public:
	SeqList(int n) :size(n), maxsize(1000) {
		list = new int[1000];
		input(list, n);
	}
	~SeqList() {
		delete[] list;
	}
	int list_size() { return size; }
	int list_insert(int i, int item)
	{
		if (i<1 || i>size + 1) { cout << "error" << endl; return error; }//插入的位置可以从1到n+1 
		for (int j = size ; j >= i; j--)
		{
			list[j ] = list[j-1];
		}
		list[i - 1] = item;
		size++;
		list_display();
		return ok;
	}
	int list_del(int i)
	{
		if (i<1 || i>size) { cout << "error" << endl; return error; }
		for (int j = i - 1; j < size - 1; j++)
		{
			list[j] = list[j + 1];
		}
		size--;
		list_display();
		return ok;
	}
	int list_get(int i)
	{
		if (i<1 || i>size) { cout << "error" << endl; return error; }
		cout << list[i - 1] << endl;
		return ok;
	}
	void list_display()
	{
		cout << size << " ";

		for (int i = 0; i < size; i++)
			cout << list[i] << " ";
		cout << endl;
	}

};
int main()
{
	int n;
	cin >> n;
	SeqList L(n);
	L.list_display();
	int x, item;
	cin >> x >> item;
	L.list_insert(x, item);
	cin >> x >> item;
	L.list_insert(x, item);
	cin >> x;
	L.list_del(x);
	cin >> x;
	L.list_del(x);
	cin >> x;
	L.list_get(x);
	cin >> x;
	L.list_get(x);


}