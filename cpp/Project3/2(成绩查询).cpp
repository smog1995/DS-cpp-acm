	#include <iostream>
	#include <cmath>
	using namespace std;
	int main()
	{
		int t;
		cin >> t;
		while (t--)
		{
			int *p;
			int n;
			cin >> n;
			int *cj = new int[n];
			for (int i = 0; i < n; i++)
				cin >> cj[i];
			p = (cj + (n / 2));
			int x;
			cin >> x;
			cout << *--p << " ";
			p++;
			cout << *++p << endl;
			p--;
			int move = abs(n / 2 - (x-1));
			if (x > n / 2)
				cout << *(p + move) << endl;
			else cout << *(p - move) << endl;

		}
	}