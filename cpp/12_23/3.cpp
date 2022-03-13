#include <iostream>
#include <map>
#include <string>
using namespace std;
template<class T>
void topticket(T *t, int n)
{
	map<T, int> maps;
	typename map<T, int>::iterator x;
	for (int i = 0; i < n; i++)
	{
		x = maps.find(t[i]);
		if (x == maps.end())
			maps.insert(pair<T, int>(t[i], 1));
		else
		{
			maps.erase(t[i]);
			maps.insert(pair<T, int>(t[i], ++(x->second)));
		}
	}
	typename map<T, int>::iterator f = maps.begin();
	for (x = maps.begin(); x != maps.end(); x++)
	{
		if ((x->second) > (f->second)) f = x;
	}
	cout << f->first << " " << f->second << endl;
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
			int *i = new int[n];
			for (int i1 = 0; i1 < n; i1++)
				cin >> i[i1];
			topticket(i, n);
			delete i;
		}
		else if (type == 'D')
		{
			double *d = new double[n];
			for (int i1 = 0; i1 < n; i1++)
				cin >> d[i1];
			topticket(d, n);
			delete d;
		}
		else if (type == 'S')
		{
			string *s = new string[n];
			for (int i1 = 0; i1 < n; i1++)
				cin >> s[i1];
			topticket(s, n);
			delete[] s;
		}
		else if (type == 'C')
		{
			char *c = new char[n];
			for (int i1 = 0; i1 < n; i1++)
				cin >> c[i1];
			topticket(c, n);
			delete c;
		}
	}
}