#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int *a = new int[n + 1];
	for (int i = 1; i < n + 1; i++)
		cin >> a[i];
	int t;
	cin >> t;
	while (t--)
	{
		int key;
		cin >> key;
		a[0] = key;
		int j;
		for (j = n; a[j] != key; j--);
		if (j == 0) cout << "error"<<endl;
		else cout << j << endl;
	}
}