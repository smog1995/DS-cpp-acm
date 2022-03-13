#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
int num = 0;
void GetNext(char *p, int* next)
{
	int i = 0, j = -1;
	int len = strlen(p);
	next[0] = -1;
	while (i < len)
	{
		if (j == -1 || p[i] == p[j]) {
			j++; i++; next[i] = j;
		}
		else j = next[j];
	}
	
}
void KMPFind(char* m,char* k, int next[])
{
	int i = -1, j = -1;
	int len1 =strlen(m), len2 =strlen(k);
	while (i < len1 && j < len2)
	{

		if (j == -1 || m[i] == k[j])
		{
			i++; j++;
		}

		else j = next[j];


		if (j == len2)
		{

			int pos = i - j + 1;
			if (pos % 2 == 1)
			{
				num++;
				
			}
			i = pos;
			j = -1;
		}
	}

}
int main()
{
	char m[10000], k[10000];

	while (scanf("%s",m)!=EOF)
	{
		if ((scanf("%s", k) == EOF)) break;
		num = 0;
		int *next = new int[strlen(k)+ 1];
		GetNext(k, next);
		KMPFind(m, k, next);
		cout << num << endl;
	}
}