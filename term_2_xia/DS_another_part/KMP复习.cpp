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
			next[i]=j;//��ǰnextֵΪƥ��ɹ��ĳ��� 
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
		//��ģʽ��ָ��λ��-1ʱ��ָ����ָ��ҲҪ�����ƶ��ˣ�
		//��������������Ϊģʽ����nextһֱ������next[0]��ûƥ��ɹ���
		//��ô��˵��������ǰ�ַ���ģʽ���е�ֵ��ƥ�䣬��Ҫ++ 
		{
			i++;j++;
		}	
		else j=next[j];//ƥ�䲻�ɹ�������ǰ׺������ǰ׺��ͬ��������±� 
	}
	if(j>=p.length()) return i-j+1;
	return -1;
	
 } 
 //ʵ�ֲ����ص��Ӵ�������������ӵĴ���Ƭ�� 
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
		 	j=next[j];//�����һ���ǰ׺��λ�� 
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
