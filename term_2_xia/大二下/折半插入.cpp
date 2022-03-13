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
		int *a = new int[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 1; i < n; i++)
		{
			int temp = a[i];
			int l = 0, h = i - 1;
			while (l <= h)
			{
				int mid =  (h + l) / 2;
				if (a[mid] < a[i]) h = mid-1;
				else  l = mid+1;
			}
			int j;
			for (j = i-1; j >= l; j--)
				a[j + 1] = a[j];
			a[j+1] = temp;
			for (int k = 0; k < n; k++)
				cout << a[k] << " ";
			cout << endl;
		}
		cout << endl;
	}
}