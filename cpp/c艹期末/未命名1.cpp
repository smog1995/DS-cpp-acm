#include  <iostream>

using namespace std;
template <class T> class Compare
{
	T a,b;
	public:
		Compare(T a1,T b1):a(a1),b(b1){
		};
		T Max()
		{
			return a>b?a:b;
		}
		T Min()
		{
			return a<b?a:b;
		}
 } ;
int main()
{
	
	int ia=2,ib=3;
	Compare<int> C(ia,ib);
	cout<<C.Max();
	cout<<" "<<C.Min();
 } 
