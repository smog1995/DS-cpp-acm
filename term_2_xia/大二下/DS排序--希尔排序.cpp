#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int *A = new int[n + 1];
		for (int i = 1; i <= n; i++)
			cin >> A[i];
		for (int g = n / 2; g >= 1; g /= 2)
		{
			for (int i = g + 1; i <= n; i++)
			{
				A[0] = A[i];
				int j;
				for (j = i - g; j >= 0 && A[j] < A[0]; j -= g)
					A[j + g] = A[j];
				A[j + g] = A[0];
			}
			for (int i1 = 1; i1 <= n; i1++)
			cout << A[i1] << " ";
			cout << endl;
		}
		cout << endl;
		
		
	}
}