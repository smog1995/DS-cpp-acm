#include <iostream>
using namespace std;
int m=999999;
void find(int x,int target,int i)
{
	if(x>2*target) return ;
	if(x==target&&m>i){
		m=i;
		cout<<m<<endl;
	}
	find(x+1,target,i+1);  
	find(x-1,target,i+1);
	find(x*2,target,i+1);
	
}
int main()
{
	int x,y;
	cin>>x>>y;
	find(x,y,0);
	cout<<m;
 } 
