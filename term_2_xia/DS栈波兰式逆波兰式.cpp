#include <iostream>
#include <stack>
#include <string>
using namespace std;
char f[7][7] =
{
	{'>','>','<','<','<','>','>' },
	{'>','>','<','<','<','>','>' },
	{'>','>','>','>','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'<','<','<','<','<','=','\0'},
	{'>','>','>','>','\0','>','>'},
	{'<','<','<','<','<','\0','='}
};
char Compare(char top,char c)
{
	int x, y;
	switch (top)//栈顶元素为列元素
	{
	case '+':x = 0; break;
	case '-':x = 1; break;
	case '*':x = 2; break;
	case '/':x = 3; break;
	case '(':x = 4; break;
	case ')':x = 5; break;
	case '#':x = 6; break;
	}
	switch (c)
	{
	case '+':y = 0; break;
	case '-':y = 1; break;
	case '*':y = 2; break;
	case '/':y = 3; break;
	case '(':y = 4; break;
	case ')':y = 5; break;
	case '#':y = 6; break;
	}
			return f[x][y];
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		str += "#";
		stack<int> opnd;
		stack<char>	optr;
		optr.push('#');
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
			{
				int x = 0;
				for (; str[i] >= '0'&&str[i] <= '9'; i++)
				{
					x = x * 10 + str[i]-'0';
				}i--;
				opnd.push(x);
			}
			else
			{
				char top = optr.top();
				if (Compare(top, str[i])=='>')
				{
					char op = top;
					int x = opnd.top(); opnd.pop();
					int y = opnd.top(); opnd.pop();
					optr.pop();
					if (op == '*') opnd.push(y*x);
					else if (op == '/') opnd.push(y / x);
					else if (op == '+') opnd.push(y + x);
					else if (op == '-') opnd.push(y - x);
					i--;//这种情况不入栈
				}
				else if(Compare(top,str[i])=='<'){
					optr.push(str[i]);
				}
				else {
					optr.pop();
				}
			}
		}

		cout << opnd.top()<<endl;
	}

}