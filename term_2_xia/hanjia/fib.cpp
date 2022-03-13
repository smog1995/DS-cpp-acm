#include <iostream>
#include <vector>
using namespace std;
int fib(int N)
{
	vector<int> dp;
	dp.push_back(1);
	dp.push_back(1);
	for(int i=2;i<=N;i++)
	{
		dp.push_back(dp[i-1]+dp[i-2]);
		cout<<dp[i]<<" ";
	}
	return dp[N];
 } 
 int main()
 {
 	cout<<fib(10);
 }
