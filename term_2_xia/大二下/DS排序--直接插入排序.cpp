#include <iostream>
using namespace std;
int main()
{
	int t;
	t = 1;
	while (t--)
	{
		int n;
		cin >> n;
		int *A = new int[n + 1];
		for (int i = 1; i <= n; i++)
			cin >> A[i];
		for (int i = 2; i <= n; i++)
		{
			A[0] = A[i];
			int j;
			for (j = i - 1; A[0]< A[j]; j--)
				A[j + 1] = A[j];
			A[j + 1] = A[0];
			for (int i1 = 1; i1 <= n; i1++)
				cout << A[i1] << " ";
			cout << endl;
		}
		cout << endl;
		
	}
}