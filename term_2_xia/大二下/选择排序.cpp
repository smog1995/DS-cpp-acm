#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
		{
			int min = i;
			for (int i1 = i+1; i1 < n; i1++)
			{
				if (a[min] > a[i1])
				{
					min = i1;
				}
			}
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
			for (int j = 0; j < n; j++)
				cout << a[j] << " ";
			cout << endl;
		}
		cout << endl;
	}
}