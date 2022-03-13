#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int* A = new int[n];
		int c = 0;
		for (int i = 0; i < n; i++)
			cin >> A[i];
		for (int i = n - 1; i >= 1; i--)
		{
			for (int i1 = 0; i1 < i; i1++)
			{
				if (A[i1] > A[i1 + 1])
				{
					int temp = A[i1];
					A[i1] = A[i1 + 1];
					A[i1 + 1] = temp;
					c++;
				}
			}
		}	cout << c << endl;
	}


}