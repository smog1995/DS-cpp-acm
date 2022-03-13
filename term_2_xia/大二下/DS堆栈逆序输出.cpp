#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	stack<char> s;
	string str;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> str;
		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			s.push(str[i]);
		}
		for (int i = 0; i < len; i++)
		{
			cout << s.top();
			s.pop();
		}
		cout << endl;
	}
}