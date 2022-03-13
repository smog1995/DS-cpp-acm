#include <iostream>
#include <string>
using namespace std;
void get_next(string str, int *next)
{
	int i = 0, j = -1;
	next[0] =-1;
	int len = str.length();
	while (i < len)
	{
		if (j == -1	 || str[i ] == str[j ]) { i++; j++; next[i] = j; }
		else j = next[j];
	}
	/*
	for (int i = 0; i <= len ; i++)
		cout << next[i] << " ";
	cout << endl;
*/
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		int len = str.length();
		int *next = new int[len+ 1];
		get_next(str, next);
		int circle = len - next[len];//主串剩下的1到多个循环串的总长
		int j = circle- len % circle; //主串除掉所有循环串后面剩下的还需多少个字符才能组成完整循环串
		if (circle != len && len % circle == 0)
			j = 0;
		cout << j << endl;
	}
}