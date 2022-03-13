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
		int circle = len - next[len];//����ʣ�µ�1�����ѭ�������ܳ�
		int j = circle- len % circle; //������������ѭ��������ʣ�µĻ�����ٸ��ַ������������ѭ����
		if (circle != len && len % circle == 0)
			j = 0;
		cout << j << endl;
	}
}