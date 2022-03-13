#include <iostream>
using namespace std;
#define ok 0
#define error -1
void input(int* L, int n)
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
	int multiinsert(int i, int n, int item[])
	{
		if (i<1 || i>size + 1) { cout << "error" << endl; return error; }
		for (int j = size+n-1; j >= i+n-1; j--)
		{
			list[j ] = list[j - n];
		}
		for (int i1 = 0, j = i-1; j < i + n-1; i1++,j++)
			list[j] = item[i1];
		size += n;
		list_display();
		return ok;
	}
	int multidel(int i, int n)
	{
		if (i<1 || i>size) { cout << "error" << endl; return error; }
		for (int j = i - 1; j <= size - n-1; j++)
		{
			list[j] = list[j + n];
		}
		size-=n;
		list_display();
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
	int idx;
	cin >> idx >> n;
	int *item = new int[n];
	input(item, n);
	L.multiinsert(idx, n, item);
	cin >> idx >> n;
	L.multidel(idx, n);

}