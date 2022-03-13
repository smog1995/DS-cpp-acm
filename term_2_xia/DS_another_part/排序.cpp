#include <iostream>
#include <vector>
using namespace std;
 void adjustSort(int *a,int k,int len)
 {
 	int temp=a[k];
// 	cout<<"k:"<<k<<" ";
 	for(int i=k*2+1;i<len;i=2*i+1)
 	{
// 		cout<<temp<<" ";
 		if(i<len-1&&a[i+1]>a[i]) i++;
 		if(temp>=a[i]) {
 			break;
		 }
		 else {
//		 	int t=a[k]; 
			 a[k]=a[i];
//		 	a[i]=t;
 			k=i;
		 }
	 }
	 a[k]=temp;
  } 
int main()
{
//	//’€∞Î≤Â»Î≈≈–Ú
	int  a[10]={1,87,17,32,45,78,65,53,9,63};
	vector<int> v;
	for(int i=0;i<10;i++)
	v.push_back(a[i]); 
	
	 int len=10;
	 //”√vector–¥≤Â≈≈
	  for(int i=1;i<v.size();i++)
	  {
	  	
	  	int j=i-1,temp=v[i];
	  	for(;j>=0&&v[j]>temp;j--)
	  	{
	  		v[j+1]=v[j];
		  }
	  	v[j+1]=temp;
	  	
	  }
	  cout<<endl;
	  cout<<"vµƒ≈≈–Ú£∫"<<endl; 
	  for(int i=0;i<v.size();i++)
	  cout<<v[i]<<" ";
	  cout<<endl;
//	 for(int i=2;i<=len;i++)
//	 {
//	 	a[0]=a[i];
//	 	int low=1,high=i-1;
//	 	while(low<=high)
//	 	{
//	 		int mid=(low+high)/2;
//	 		if(a[mid]<a[0]) low=mid+1;
//	 		else high=mid-1;
//	 		
//		}
//		for(int j=i-1;j>=low;j--)
//		a[j+1]=a[j];
//		a[low]=a[0];
//	 }
//	 for(int i=0;i<=len;i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
//	//÷±Ω”≤Â»Î≈≈–Ú
//	for(int i=2;i<=len;i++)
//	{
//		a[0]=a[i];
//		int j;
//		for(j=i-1;j>=1&&a[j]>a[0];j--)
//		a[j+1]=a[j];
//		a[j+1]=a[0];
//	}
//	 for(int i=0;i<=len;i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
	//œ£∂˚≈≈–Ú
//	 for(int dk=len/2;dk>=1;dk/=2)
//	 {
//	 	for(int i=dk+1;i<=len;i++)
//	 	{
//	 		int j;
//	 		a[0]=a[i];
//	 		for(j=i-dk;j>=1&&a[j]>a[0];j-=dk)
//	 		a[j+dk]=a[j];
//	 		a[j+dk]=a[0];
//		}
//	 }
//	 for(int i=0;i<=len;i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
//	//∂—≈≈
//	 for(int i=len/2;i>=1;i--)
//	 {
//	 	adjustSort(a,i,len);
//	 }
//	 for(int i=1;i<=len;i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
	for(int i=len/2-1;i>=0;i--)
	adjustSort(a,i,len);
	for(int i=0;i<len;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	for(int i=0;i<len;i++)
	{
		int t=a[0];
		a[0]=a[len-i-1];
		a[len-i-1]=t;
		adjustSort(a,0,len-i-1);
	}
	for(int i=0;i<len;i++)
	cout<<a[i]<<" ";
	cout<<endl;
 }
// for(int i=(size-1)/2;i>=0;i--)
// 	heapadjust(a,i,size);
//
//
//void heapadjust(int* a,int k,int size)
//{
//	int temp=a[k];
//	for(int j=2*k+1;j<size;j=2*j+1)
//	{
//		if(j<size-1&&a[j]<a[j+1]) j++;
//		if(a[j]>temp) 
//		{
//			a[j]=temp;
//			k=j;
//		} 
//	}
//	a[k]=temp;
//}
/*øÏ≈≈ 
int partition(int *a,int low,int high)
{
	int pivot=a[low];
	while(low<high)
	{
		while(low<high&&pivot<=a[high] )high--;
		a[low]=a[high];
		while(low<high&&pivot>=a[low]) low++;
		a[high]=a[low];
	}
	a[low]=pivot;
	return low;
}
void QuickSoct(int * a,int low,int high)
{
	if(high<low)
	{
		int p=partition(a,low,high);
		QuickSort(a,low,p-1);
		QuickSort(a,p+1,high);
	}
}
*/
//πÈ≤¢≈≈–Ú
void Merge(int *a,int l,int m,int h)
{
	int *b=new int[n+1];
	for(int i=l;i<h;i++)
	b[i]=a[i];
	for(int i=l,j=m+1,k=0;i<=m&&j<=h;k++)
	{
		if(b[])
	}
}
void MergeSort(int *a,int l,int h)
{
	if(l<h)
	{
		int mid=(l+h)/2;
		MergeSort(a,low,mid);
		MergeSort(a,mid+1,h);
		Merge(a,l,m,h);
	}
 } 
