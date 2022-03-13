#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
 	for(int i=0;i<n;i++)
 	a[i]=i;
 	vector<int> v;
	 for(int i=5;i<n;i++)
 		v.push_back(a[i]);
 		for(int i=0;i<v.size();i++)
 		cout<<v[i]<<" ";
 		cout<<endl;
 		vector<int > v1;
 		cout<<v1.size();
 } 
