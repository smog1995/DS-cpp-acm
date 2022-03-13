#include <iostream>
#include <string>
using namespace std;
int num = 0;
void GetNext(string p, int* next)
{
	int i = 0, j = -1;
	int len = p.length();
	next[0] = -1;
	while (i < len)
	{
		if (j == -1 || p[i] == p[j]) {
			j++; i++; next[i] = j;
		}
		else j = next[j];
	}
	for(int i=0;i<len;i++)
	cout<<next[i]<<" ";
	cout<<endl;
}
void KMPFind(string &m,string &k, int next[])
{
	int i = -1,j = -1;
	int len1=m.length(),len2=k.length();
	while (i <len1 && j < len2)
	{
		
		if (j==-1||m[i] == k[j])
		{
			i++; j++;
		}
		
		else j = next[j];
		
		
		if (j == k.length() )
		{
			
			int pos = i - j + 1;
			if (pos % 2 == 0)
			{
				num++;
				j = 0;
			}
		}
	}
	
}
int main()
{
	string m, k;
	cin >> m;
	cin >> k;
	while (1)
	{
		num = 0;
		int *next = new int[k.length() + 1];
		GetNext(k, next);
		KMPFind(m, k, next);
		cout << num<<endl;
		cin >> m;
		cin >> k;
	}
}
