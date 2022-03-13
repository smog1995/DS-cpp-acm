#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> m >> n;

		int *A = new int[m];
		for (int i = 0; i < m; i++)
			A[i] = -1;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			int y = x % 11;
			int crush = 0;
			while (A[(y + crush) % m] != -1)
				crush++;
			A[(y + crush) % m] = x;
		}
		for (int i = 0; i < m; i++)
		{
			if (A[i] == -1) cout << "NULL ";
			else cout << A[i] << " ";
		}
		cout << endl;
		int num;
		cin >> num;
		while (num--)
		{
			int x;
			cin >> x;
			int y = x % 11;
			int count = 1;
			while (A[y] != x&&A[y]!=-1)
			{
				count++;
				y =(y+1)%m;
			}
			if (A[y] != x) cout << "0 " << count << endl;
			else cout << "1 " << count << " "<<y + 1 << endl;
		}
	}
	
	


}