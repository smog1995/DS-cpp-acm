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
	
	void list_display()
	{
		cout << size << " ";

		for (int i = 0; i < size; i++)
			cout << list[i] << " ";
		cout << endl;
	}
	int* unite(SeqList& L2)
	{
		int i = 0,i1=0,i2=0;
		int *L3 = new int[list_size() + L2.list_size()];
		while (i1<list_size()&&i2<L2.list_size() )
		{
			if (list[i1] < L2.list[i2]) L3[i++] = list[i1++];
			else L3[i++] = L2.list[i2++];
		}
		while (i1 < list_size())
		{
			L3[i++] = list[i1++];
		}
		while(i2<L2.list_size())
			L3[i++] = L2.list[i2++];
		return L3;
	}

};
int main()
{
	int n1;
	cin >> n1;
	SeqList L1(n1);
	int n2;
	cin >> n2;
	SeqList L2(n2);

	int len = n1 + n2;
	int *L3 =L1.unite(L2);
	cout << n1 + n2 << " ";
	for (int i = 0; i < n1 + n2; i++)
		cout << L3[i] << " ";

}