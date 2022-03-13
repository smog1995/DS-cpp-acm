#include <iostream>
using namespace std;
class matrix
{
	int m, n,**data;
public:
	matrix(int m1, int n1);
	matrix(matrix &m);
	~matrix() { delete[] data; }
	void print();
	matrix operator+(matrix&);
};
matrix::matrix(matrix &M)
{
	m=M.m;
	n=M.n;
	data = new int*[m];//指向指针数组的指针
	for (int i = 0; i < m; i++)
	{
		data[i] = new int[n];//对每个指针数组中的指针进行动态分配
	}
	for(int i=0;i<m;i++)
		for(int i1=0;i1<n;i1++)
		data[i][i1]=M.data[i][i1];
}
matrix matrix::operator+(matrix& m1)
{
	for (int i = 0; i <m; i++)
	{
		for (int i1 = 0; i1 < n; i1++)
		{
			data[i][i1] += m1.data[i][i1];
		}
	}
	return *this;
}
	
matrix::matrix(int m1, int n1):m(m1),n(n1)
{
	data = new int*[m1];//指向指针数组的指针
	for (int i = 0; i < m1; i++)
	{
		data[i] = new int[n1];//对每个指针数组中的指针进行动态分配
	}
	for(int i=0;i<m1;i++)
		for (int i1 = 0; i1 < n1; i1++)
		{
			cin >> data[i][i1];
		}
}
void matrix::print()
{
	for (int i = 0; i < m; i++)
	{
		for (int i1 = 0; i1 < n; i1++)
		{
			cout << data[i][i1] << " ";
		}
		cout << endl;
		
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m, n;
		cin >> m >> n;
		matrix m1(m, n);
		matrix m2(m, n);
		(m1 + m2).print();
	}
}
