#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string  str;
		stack<char> s;
		cin >> str;
		char c;
		int flag = 0;
		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			if (!s.empty()) c = s.top();
			if (str[i] == '(' || str[i] == '[' || str[i] == '{') s.push(str[i]);

			else if (str[i] == ')')
			{
				if (s.empty()) {
					flag = 1;
					break;
				}
				if (c != '(')
				{
					break;
				}
				else s.pop();
			}
			else if (str[i] == ']')
			{
				if (s.empty()) {
					flag = 1;
					break;
				}
				if (c != '[')
				{
					break;
				}
				else s.pop();
			}
			else if (str[i] == '}')
			{
				if (s.empty()) {
					flag = 1;
					break;
				}
				if (c != '{')
				{
					break;
				}
				else s.pop();
			}
		}
		if (!s.empty()||flag==1) cout << "error" << endl;
		else if(flag==0)cout << "ok" << endl;
	}
}