#include <iostream>
#include <cstring>
#define MaxSize 100 
using namespace std;

char stack[MaxSize];
int top;
void InitStack(char* S)
{
	top=-1;
}
bool Push(char* S,char x)
{
	if(top==MaxSize-1) return false;
	S[++top]=x;
	return true;
}
bool Pop(char* s,char &x)
{
	if(top==-1) return false;
	x=s[top--];
	return true;
}
bool Empty()
{
	return top==-1;
}
int main()
{
	InitStack(stack);
	char str[10];
	cin>>str;
	for(int i=0;i<strlen(str);i++)
	cout<<str[i];
	cout<<endl;
	int flag=1;
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]=='('||str[i]=='['||str[i]=='{') Push(stack,str[i]);
		else 
		{
			if(Empty()) {
				cout<<"false(栈是空的)"<<endl;
				flag=0;
				break; 
			}
			char x;
			Pop(stack,x);
			if((x=='('&&str[i]!=')')||(x=='['&&str[i]!=']')||(x=='{'&&str[i]!='}')) 
			{
				cout<<"false(匹配括号对不上)"<<endl;
				flag=0;
				break;
			}
		}
	}
	if(flag==1&&Empty()) cout<<"匹配成功"<<endl;
	else if(flag==1&&!Empty())
	{
		cout<<"false:栈里还有括号"<<endl;
	}
	
}
