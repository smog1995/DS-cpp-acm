#include <iostream>
#include<string>
#include <stack>
using namespace std;
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		stack<char> s;
		string str;
		cin >> str;

		for(int i=0;i<str.length();i++)
		{
			if (str[i] == '#') {
				if (!s.empty())
					//	cout << s.top();
					s.pop();
			}
			else s.push(str[i]);
		}
		/*
		string str2;
		int i1 = 0;
		while(!s.empty())
		{
			str2[i1++] = s.top();
			s.pop();
		}
		int len2 = str2.length();
		if (len2!=0)
		{
			for (int i = i1; i >= 0; i--)
				cout << str2[i];
		}
		else cout << "NULL";
		cout << endl;
	*/
		stack<char> s1;
		while (!s.empty())
		{
			char x = s.top();
			//cout << x << "????";
			s1.push(x);
			s.pop();
		}
		if (!s1.empty())
			while (!s1.empty())
			{

				cout << s1.top();
				s1.pop();
			}
		else cout << "NULL";
		cout << endl;

	}
}