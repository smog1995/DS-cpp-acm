#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int k;
	cin >> k;
	int *b = new int[k];
	for (int i = 0; i < k; i++)
		cin >> b[i];
	int len = n / k;
	int t;
	cin >> t;
	while (t--)
	{
		int key;
		cin >> key;
		int count = 0;
		int j1 = 0, j2;
		for (; j1 < k&&b[j1] < key; j1++, count++);
		count++;
		for (j2 = j1 * len; j2 < (j1 + 1)*len; j2++, count++)
		{
			if (a[j2] == key)
			{
				count++;
				cout << j2 + 1 << "-" << count << endl;
				break;
			}
		}
		if (j2 == (j1 + 1)*len) cout << "error" << endl;

	}
}