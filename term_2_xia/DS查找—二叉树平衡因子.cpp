#include <iostream>
using namespace std;
int a[1000];
char b[1000];
int top = -1;
int depth(int i,char *c,int n)
{
	if (i > n - 1||c[i]=='0') return 0;
	int ld = depth(2 * i+1, c, n);
	int rd = depth(2 * i + 2, c, n);
	a[++top] = ld - rd;
	b[top] = c[i];
	return ld > rd ? ld+1 :rd+1 ;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		char *C = new char[n+1];
		for (int i = 0; i < n; i++)
			cin >> C[i];
		depth(0, C, n);
		for (int i = 0; i <= top; i++)
			cout <<b[i] << " " << a[i]<<endl;
		top = -1;
	}
}