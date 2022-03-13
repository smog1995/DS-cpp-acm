#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int b[100000][2];
void Merge(int a[][2], int l, int r, int m)
{
	
	for (int i = l; i <= r; i++)
	{
		b[i][0] = a[i][0];
		b[i][1] = a[i][1];
	}
	int i, j, k;
	for (i = l, j = m + 1, k = l; i <= m && j <= r; k++)
	{
		if (b[i][0] <=b[j][0]) {
			*(*(a+k)+0) = *(*(b + i) + 0);
			*(*(a + k) + 1) = *(*(b + i) + 1);
			i++;
		}
		else {
			*(*(a + k) + 0) = *(*(b + j) + 0);
			*(*(a + k) + 1) = *(*(b + j) + 1);
			j++;
		}
	}
	while (i <= m) {
		*(*(a + k) + 0) = *(*(b + i) + 0);
		*(*(a + k) + 1) = *(*(b + i) + 1);
		k++; i++;
	}
	while (j <= r) {
		*(*(a + k) + 0) = *(*(b + j) + 0);
		*(*(a + k) + 1) = *(*(b + j) + 1);
		k++; j++;
	}
}
void MergeSort(int a[][2], int l, int r)
{
	if (l < r)
	{
		int m = (l+r) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		Merge(a, l, r, m);
	}
}
int main()
{
	int a[100000][2];
	
	while (scanf("%d",&n) !=EOF)
	{

		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &a[i][0], &a[i][1]);
		}
		//MergeSort(a, 0, n - 1);
		int size = 1;
		int l = 0, r = 0, m = 0;
		while (size <= n - 1)
		{
			l = 0;
			while (l+size <= n - 1)
			{
				m = l + size-1;
				r = m+size;
				if (r > n - 1) r = n - 1;
				
				Merge(a,l,r,m);
				l = r + 1;
			}
			size *= 2;
		}
		for (int i = 0; i < n; i++)
			printf("%d %d\n", a[i][0], a[i][1]);// << a[i][0] << " " << a[i][1] << endl;
		//fflush(stdin);
		
	}
	
}