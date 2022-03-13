#include <iostream>
using namespace std;
template<class T> void print(T** t, int n)
{
	for (int i = 1; i >= 0; i--)
	{
		for (int i1 = 0; i1 < n; i1++)
			cout << t[i][i1];
	}
	cout << endl;
}
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
			int **integer = new int*[2];
			integer[0] = new int[n];
			integer[1] = new int[n];
			for (int i = 0; i <= 1; i++)
				for (int i1 = 0; i1 < n; i1++)
					cin >> integer[i][i1];
			print(integer, n);
			delete[] integer;
		}
		else if (type == 'D')
		{
			double **D = new double*[2];
			D[0] = new double[n];
			D[1] = new double[n];
			for (int i = 0; i <=1; i++)
				for (int i1 = 0; i1 < n; i1++)
					cin >>D[i][i1];
			print(D, n);
			delete[] D;
		}
		else if (type == 'C')
		{
			char **C = new char*[2];
			C[0] = new char[n];
			C[1] = new char[n];
			for (int i = 0; i <= 1; i++)
				for (int i1 = 0; i1 < n; i1++)
					cin >> C[i][i1];
			print(C, n);
			delete[] C;
		}
	}
}