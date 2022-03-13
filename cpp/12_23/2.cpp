#include <iostream>
#include <string>
using namespace std;
template<class T> int find(T* t, int n, T key)
{
	int  x=0;
	for (int i = 0; i < n; i++)
	{
		if (key == t[i]) x = i + 1;
	}
	return x;
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
			int findi;
			for (int i = 0; i < n; i++)
				cin >> a[i];
			cin >> findi;
			cout << find(a, n, findi) << endl;
			delete a;

		}
		else if (type == 'D')
		{
			double *d = new double[n];
			double findd;
			for (int i = 0; i < n; i++)
				cin >> d[i];
			cin >> findd;
		
			cout << find(d, n, findd)<< endl;
			delete d;
		}
		else if (type == 'S')
		{
			string *s = new string[n];
			string finds;
			for (int i = 0; i < n; i++)
				cin >> s[i];
			cin >> finds;
			cout << find(s, n, finds) << endl;
			delete[] s;
		}
		else if (type == 'C')
		{
			char *c = new char[n];
			char findc;
			for (int i = 0; i < n; i++)
				cin >> c[i];
			cin >> findc;
			cout << find(c, n, findc) << endl;
			delete c;
		}
	}
}