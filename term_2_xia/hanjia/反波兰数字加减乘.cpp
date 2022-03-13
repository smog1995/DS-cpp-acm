#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 1000
int top=-1,S[MAX];
void Push(int x)
{
	S[++top]=x;
}
int Pop()
{
	return S[top--];
}


int main()
{
	char s[100];
	while((scanf("%s",s))!=EOF)
	{
		int a,b;
		if(s[0]=='+') 
		{
			a=Pop();
			b=Pop();
			Push(b+a); 
		}
		else if(s[0]=='-')
		{
			a=Pop();
			b=Pop();
			Push(b-a); 	
		}
		else if(s[0]=='*')
		{
			a=Pop();
			b=Pop();
			Push(a*b); 
		}
		else 
		{
			int res=0;
			for(int i=0;s[i]>='0'&&s[i]<='9';i++)
			res=res*10+s[i]-'0';
			Push(res);
		}
	}
 	cout<<Pop()<<endl;
 } 
