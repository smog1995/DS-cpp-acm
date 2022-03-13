#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int x, y;
	while (scanf("%d %d", &x, &y) != EOF)
	{
		int flag = 0;
		while (x&&y&&!flag)
		{
			int x1 = x > y ? x : y, y1 = x < y ? x : y;
			while (x1)
			{
				if (x1 == y1)
				{
					cout << x1 << endl;
					flag = 1;
					break;
				}
				x1 /= 2;
			}
			if (flag == 1) break;
			if (x==y)
			{
				cout << x << endl;
				flag = 1;
			}
			else if (x / 2 == y / 2)
			{
				
				cout << x / 2 << endl;
				flag = 1;
			}
			else if (x / 2 == y ) {
				cout << y << endl;
				flag = 1;
			}
			else if (x == y / 2)
			{
				cout << x << endl;
				flag = 1;
			}
			if(x!=1)x /= 2;
			if(y!=1)y /= 2;
		}
		
	}
}