#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int n;
int level;
void Merge(string* a, int l, int r, int m)
{
	string *b = new string[n];
	for (int i = l; i <= r; i++)
		b[i] = a[i];
	int i, j, k;
	for (i = l, j = m + 1, k = l; i <= m && j <= r; k++)
	{
		if (b[i] > b[j]) a[k] = b[i++];
		else a[k] = b[j++];
	}
	while (i <= m) {
		a[k++] = b[i++];
	}
	while (j <= r)a[k++] = b[j++];
	
}

void MergeSort(string *a, int l, int r,int x)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		MergeSort(a, l, m,2*x+1);
		MergeSort(a, m + 1, r,2	*x+2);
		Merge(a, l, r,m);
		if (x == n - 1 || (log(x + 1) / log(2)) == level-1)
		{
			for (int i = 0; i < n; i++)
				cout << a[i] << " ";
			cout << endl;
			level--;
		}
		
	}
	
	
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		string *a = new string[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		level = log(n) / log(2);
		if ((log(n) / log(2)) - level>0) level += 1;
		MergeSort(a, 0, n - 1, 0);
		cout << endl;
	}
}