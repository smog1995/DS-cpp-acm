#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int t;
	cin >> t;
	while (t--)
	{
		int high = n - 1, low = 0, mid;
		int key;
		cin >> key;
		while (low <= high)
		{
			mid = low + (high - low) / 2;
			if (a[mid] == key) {
				cout << mid + 1 << endl;
				break;
			}
			else if (a[mid] > key) high = mid - 1;
			else if (a[mid] < key) low = mid + 1;
		}
		if (low > high) cout << "error" << endl;
	}
}