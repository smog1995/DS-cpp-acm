#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Child {
public:
	int no;
	char c;
	Child(int n,char c1):no(n),c(c1){}
	~Child() {

	}
};
int main()
{
	string str;
	cin >> str;
	int len = str.length();
	stack<Child *> s;
	char c1, c2;
	c1 = str[0];
	for(int i=0;i<len;i++)
		if (str[i] != c1)
		{
			c2 = str[i];
			break;
		}
	for (int i = 0; i < len; i++)
	{
		
		if (str[i] == c2)
		{
			Child* C = s.top();
			if (C->c == c1)
			{
				s.pop();
				cout <<C->no << " " << i << endl;
			}
				
		}
		else {
			Child *c = new Child(i, str[i]);
			s.push(c);
		}
	}

}