#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int n;
	cin >> n;
	queue<int> A;
	queue<int> B;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x % 2) A.push(x);
		else B.push(x);
	}
	while (!A.empty() || !B.empty())
	{
		for(int i1=0;i1<2;i1++)
			if (!A.empty())
			{
				cout << A.front() << " ";
				A.pop();
			}
		if (!B.empty())
		{
			cout << B.front() << " ";
			B.pop();
		}
	}

}