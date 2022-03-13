#include<iostream>
using namespace std;
int n;
int partition(int *a,int l, int r) {
int pivot=a[l];
 while(l<r) {
  	while(l<r&&a[r]>=pivot) r--;
  	a[l]=a[r];
  	while(l<r&&a[l]<=pivot) l++;
  	a[r]=a[l];
 }
 a[l]=pivot;
 cout<<a[l]<<" "<<endl;;
 return l;
}

void QSort(int* l, int low, int high) {
 int mid;
 if (low < high) {
  mid = partition(l, low, high);
  QSort(l, low, mid - 1);
  if(low==mid-1) cout<<a[]
 QSort(l, mid + 1, high);
 }
 
}

int main() {
 int t;
 int a[100];
 cin >> t;
 while (t--) {
  cin >> n;
  for (int i = 0;i < n;i++) {
   cin >> a[i];
  }
  QSort(a, 0, n-1 );
  cout << endl;
 }
}
