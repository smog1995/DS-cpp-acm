#include <iostream>
#include <iomanip>
#include <memory.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int *a1=new int[n];
		int *a2=new int[n];
		for(int i=0;i<n;i++)
		cin>>a1[i]>>a2[i];
		int m;
		cin>>m;
		int* b1=new int[m];
		int* b2=new int[m];
		for(int i=0;i<m;i++)
		cin>>b1[i]>>b2[i];
		int *c1=new int[m+n];
		int *c2=new int[m+n];
		memset(c1, 0, sizeof(int));
		memset(c2, 0,sizeof(int));
		int j=0,k=0,l=0;
		for(;j<n&&k<m;l++)
		{
			if(a2[j]==b2[k]) {
				c1[l]=a1[j]+b1[k];
				c2[l]=a2[j];
				cout << "c1¡¾l¡¿£º" << c1[l] << "c2¡¾l¡¿:" << c2[l] << endl;
				j++;k++;
			}
			else if(a2[j]>b2[k])
			{
				c1[l]=b1[k];
				c2[l]=b2[k];
				cout << "c1¡¾l¡¿£º" << c1[l] << "c2¡¾l¡¿:" << c2[l] << endl;
				k++;
			}
			else {
				c1[l]=a1[j];
				c2[l]=a2[j];
				cout << "c1¡¾l¡¿£º" << c1[l] << "c2¡¾l¡¿:" << c2[l] << endl;
				j++;
			}

		}
		while(j<m)
		{
			c1[l]=a1[j];
			c2[l++]=a2[j++];
		}
		while(k<m)
		{
			c1[l]=b1[k];
			c2[l++]=b2[k++];
		}
		for (int i = 0; i < n; i++)
		{
			if (a1[i] == 0) continue;
			cout << a1[i];
			if (a2[i] == 0) cout << " +";
			else
				cout << "x^" << a2[i] << " +";
		}cout << endl;
		for (int i = 0; i < m; i++)
		{
			if (b1[i] == 0) continue;
			cout << b1[i];
			if (b2[i] == 0) cout << " +";
			else
				cout << "x^" << b2[i] << " +";
		}cout << endl;
		for(int i=0;i<l;i++)
		{
			if(!c1[i]) continue;
			cout<<c1[i];
			if(c2[i]==0) cout<<" +";
			else
			cout<<"x^"<<c2[i]<<" +";
		}
		cout<<endl;
	}
}

