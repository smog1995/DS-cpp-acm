#include <iostream>
#include <stack>
using namespace std;
int main()
{
	
	int n;
	cin>>n;
	string str;
	while(n--)
	{
		stack<char> s;
		cin>>str;
		for(int i=0;i<str.length();i++)
		{
			if(str[i]=='#')
			{
				if(!s.empty())
				s.pop();
			}
			else s.push(str[i]);
		}
		stack<char> s2;
		while(!s.empty())
		{
			s2.push(s.top());
			s.pop();
		}
		if(s2.empty()) cout<<"NULL";
		while(!s2.empty())
		{
			cout<<s2.top();
			s2.pop();
		}	
		
			cout<<endl;
	}
 } 
