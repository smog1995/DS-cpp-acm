#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#define MaxSize 10000
#define error -999999
using namespace std;
//+ - * / ( ) #
//波兰数，入栈顺序为表达式从右往左，倒过来了，所以相应的优先级会相反 
//12+3*5+(2+10)*5  
char f1[7][7] =
{
	{'<','<','<','<','>','<','>'},
	{'<','<','<','<','>','<','>'},
	{'>','>','<','<','>','<','>'},
	{'>','>','<','<','>','<','>'},
	{'>','>','>','>','>','=','>'},
	{'<','<','<','<','=','<','>'},
	{'<','<','<','<','<','<','='}
};
char f2[7][7] =
{
	{'>','>','<','<','<','>','>' },
	{'>','>','<','<','<','>','>' },
	{'>','>','>','>','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'<','<','<','<','<','=','\0'},
	{'>','>','>','>','\0','>','>'},
	{'<','<','<','<','<','\0','='}
};

class Node {
public:
	int num;
	char op;
	Node() {
		num = -999999;
		op = '!';
	}

};
char Compare(char top, char c, char f[][7])
{
	int x = 0, y = 0;
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
		stack<int> opnd;
		stack<char> optr1;
		stack<char> optr2;
		string str;
		cin >> str;
		optr1.push('#');
		optr2.push('#');
		string str1 = "#" + str;
		str += "#";
		//求波兰
		Node *Stack = new Node[str1.length()];
		int Top = -1;
		for (int i = str1.length() - 1; i >= 0; i--)
		{
			if (str1[i] >= '0'&&str1[i] <= '9')
			{
				int x = 0, i1 = 0;
				for (; str1[i] >= '0'&&str1[i] <= '9'; i--)
				{
					x += (str1[i] - '0')* pow(10, i1++);
				}i++;
				Stack[++Top].num = x;
			}
			else {
				char top = optr2.top();
				if (Compare(top, str1[i], f1) == '>')
				{

					Stack[++Top].op = top;
					optr2.pop();//同时将操作符入栈   
					i++;
				}
				else if (Compare(top, str1[i], f1) == '<')
				{
					optr2.push(str1[i]);
				}
				else optr2.pop();
			}
		}
		while (Top != -1)
		{
			if (Stack[Top].num != error) cout << Stack[Top--].num << " ";
			else cout << Stack[Top--].op << " ";
		}
		cout << endl;



		//求逆波兰 
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
			{
				int x = 0;
				for (; str[i] >= '0'&&str[i] <= '9'; i++)
				{
					x = x * 10 + str[i] - '0';
				}i--;
				cout << x << ' ';
			}
			else {
				char top = optr1.top();
				if (Compare(top, str[i], f2) == '>')
				{
					cout << top << " ";
					optr1.pop();
					i--;
				}
				else if (Compare(top, str[i], f2) == '<')
				{
					optr1.push(str[i]);
				}
				else optr1.pop();
			}

		}cout << endl;
		cout << endl;
	}
}