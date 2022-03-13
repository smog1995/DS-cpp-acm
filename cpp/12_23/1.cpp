#include <iostream>
#include <string>
#include <vector>
using namespace std;
template<class T> void Sort(T *t,int n)
{
	T temp;
	for (int i = 0; i <n;i++ )
	{
		for (int i1 = i + 1; i1 < n; i1++)
		{
			if (t[i] > t[i1])
			{
				temp = t[i];
				t[i] = t[i1];
				t[i1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << t[i] << " ";
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		char type;
		cin >> type >> n;
		if (type == 'I')
		{
			int *a = new int[n];
			for (int i = 0; i < n; i++)
				cin >> a[i];
			Sort(a, n);
			delete a;
			
		}
		else if (type == 'D')
		{
			double *d=new double[n];
			for (int i = 0; i < n; i++)
				cin >> d[i];
			Sort(d, n);
			delete d;
		}
		else if (type == 'S')
		{
			string *s=new string[n];
			for (int i = 0; i < n; i++)
				cin >> s[i];
			Sort(s, n);
			delete[] s;
		}
		else if (type == 'C')
		{
			char *c = new char[n];
			for (int i = 0; i < n; i++)
				cin >> c[i];
			Sort(c, n);
			delete c;
		}
	}
}
		/*		vector<int> *a;
				vector<char> *c;
				vector<string> *s;
				vector<double> *d;
				if (t == 'I')
				{
					a = new vector<int>;
					for (int i = 0; i < n; i++)
					{
						a=
					}
				}
				else if (t == 'C')
				{
					c = new vector<char>;
					for (int i = 0; i < n; i++)
					{

					}
				}
				*/
