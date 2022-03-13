
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;


struct num
{
	int data1;
	int data2;
	int id;
} Num[100005], T1[100005];


void merge_sort(num* A, int x, int y, num* T)//归并排序:等值元素不更改原数组中位置。
{
	if (y - x > 1)
	{
		int m = x + (y - x) / 2;
		int p = x, q = m, i = x;
		merge_sort(A, x, m, T);
		merge_sort(A, q, y, T);


		while (p < m || q < y)
		{
			if (q >= y || (p < m&&A[p].data1 <= A[q].data1))
			{
				T[i].data1 = A[p].data1;
				T[i].data2 = A[p].data2;
				T[i++].id = A[p++].id;
			}
			else
			{
				T[i].data1 = A[q].data1;
				T[i].data2 = A[q].data2;
				T[i++].id = A[q++].id;
			}
		}
		for (int i = x; i < y; i++)
		{
			A[i].data1 = T[i].data1;
			A[i].data2 = T[i].data2;
			A[i].id = T[i].id;
		}


	}
}


int main()
{


	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &Num[i].data1, &Num[i].data2);
			Num[i].id = i;
		}


		merge_sort(Num, 0, n, T1);
		for (int i = 0; i < n; i++)
		{
			printf("%d %d\n", Num[i].data1, Num[i].data2);
		}
	}
	return 0;
}