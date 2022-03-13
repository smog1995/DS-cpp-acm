#include <iostream>
using namespace std;
void get_next(string p,int next[])
{
	int i=0,j=-1;
	next[0]=-1;
	while(i<p.length())
	{
		if(j==-1||p[i]==p[j]){
			i++;j++; 
			next[i]=j;//当前next值为匹配成功的长度 
		}
		else j=next[j];
	}
}
int FindKMP(string s,string p,int pos,int* next)
{
	int i=pos,j=0;
	while(i<(int)s.length()&&j<(int)p.length())
	{
		if(j==-1||s[i]==p[j])
		//当模式串指针位于-1时是指主串指针也要跟着移动了，
		//造成这种情况是因为模式串的next一直跳到了next[0]还没匹配成功，
		//那么就说明主串当前字符与模式串中的值不匹配，需要++ 
		{
			i++;j++;
		}	
		else j=next[j];//匹配不成功，跳到前缀与主串前缀相同部分最长的下标 
	}
	if(j>=p.length()) return i-j+1;
	return -1;
	
 } 
 //实现查找重叠子串，这里有新添加的代码片段 
 int KMPFind2(string s,string p,int pos,int *next)
 {
 	int i=pos,j=0;
 	int count=0;
 	int len1=s.length(),len2=p.length();
 	while(i<len1&&j<len2)
 	{
 		if(j==-1||s[i]==p[j]) {
 			i++;j++;
		 }
		 else j=next[j];
		 if(j==len2)
		 {
		 	count++;
		 	j=next[j];//检查上一个最长前缀的位置 
		 }
	 }
	 return count;
 }
 void findSub(string s,string p)
 {
 	int *next=new int[p.length()];
		get_next(p,next);
	cout<<p<<":"<<KMPFind2(s,p,0,next)<<endl;
		
	delete[] next;
 }
int main()
{

		string s,p;
		int n;
		cin>>s;
		cin>>n;
		while(n--)
		{
			cin>>p;
		findSub(s,p);
		}

}
