#include <iostream>
using namespace std;

template <typename T>
class BoundArray
{
	T *data;
	int n;
public:
	BoundArray(int n1,T* d):n(n1)
	{
		data = new T[n];
		for (int i = 0; i < n; i++)
			data[i] = d[i];
	}
	~BoundArray() { delete[] data; };
	void Print()
	{
		for (int i = 0; i < n; i++)
			cout << data[i] << " ";
		cout << endl;
	}
	void sort()
	{
		for(int i=0;i<n;i++)
			for (int i1 = i + 1; i1 < n; i1++)
			{
				if (data[i] > data[i1])
				{
					T temp = data[i];
					data[i] = data[i1];
					data[i1] = temp;
				}
			}
	}
	T search(T t)
	{
		for (int i = 0; i < n; i++)
			if (t == data[i]) return i;
		return -1;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char type;
		int n;
		cin >> type >> n;
		if (type == 'I')
		{
			int *I = new int[n];
			for (int i = 0; i < n; i++)
				cin >> I[i];
			BoundArray<int> b(n, I);
			b.sort();
			b.Print();
			int e;
			cin >> e;
			cout<<b.search(e)<<endl;
		}
		else if (type == 'D')
		{
			double *D = new double[n];
			for (int i = 0; i < n; i++)
				cin >> D[i];
			BoundArray<double> bd(n, D);
			bd.sort();
			bd.Print();
			double de;
			cin >> de;
			cout<<bd.search(de)<<endl;
		}
		else if (type == 'C')
		{
			char *C = new char[n];
			for (int i = 0; i < n; i++)
				cin >> C[i];
			BoundArray<char> bc(n, C);
			bc.sort();
			bc.Print();
			char ce;
			cin >> ce;
			cout<<bc.search(ce)<<endl;
		}
	}
}