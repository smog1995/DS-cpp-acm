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
			int count = 0;
			int cr = 0,flag=0;
			while (A[(y + cr+m) % m] != -1&&count<=m/2)
			{
				if (!flag)
				{
					count++;
					flag = 1;
					cr = count * count;
				}
				else {
					cr = -cr;
					flag = 0;
				}
				
			}
			A[(y + cr+m) % m] = x;
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
			int count = 0,c=1;
			int cr = 0,flag=0;
			while (A[(y +cr) % m] != x && A[(y + cr) % m] != -1&&count<=m/2)
			{
				c++;//比较次数
				if (!flag)
				{
					count++;
					flag = 1;
					cr = count * count;
				}
				else {
					cr = -cr;
					flag = 0;
				}
			}
			if (A[(y + cr)%m] != x) cout << "0 " << c << endl;
			else cout << "1 " << c << " " << (y+cr)%m+1<< endl;
		}
	}




}