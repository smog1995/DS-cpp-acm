#include <iostream>
using namespace std;
void comp(char a,char b)
{
	if(a>b) cout<<a<<">"<<b<<endl;
}
int main()
{
	char a='B',b='D';
	comp(a,b);
	a='d';
	comp(a,b);
	a='1';
	b='2';
	comp(a,b);
 } 
