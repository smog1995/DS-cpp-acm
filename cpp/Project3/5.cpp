#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char C;
		cin >> C;
		int n;
		cin >> n;
		if (C == 'I')
		{
			int *I = new int[n];
			int averge= 0;
			for (int i = 0; i < n; i++)
			{
				cin >> *(I + i);
				averge += *(I + i);
			}
			averge /= n;
			cout << averge << endl;

		}
		else if (C == 'F')
		{
			float *F = new float[n];
			float min = 999999;
			for (int i = 0; i < n; i++)
			{
				cin >> *(F+i);
				if (min > *(F + i)) min = *(F + i);

			}
			cout << min << endl;
		}
		else if (C == 'C')
		{
			char *CH = new char[n];
			cin >> *(CH + 0);
			char max= *(CH + 0);
			for (int i = 1; i < n; i++)
			{
				cin >> *(CH + i);
				if (*(CH + i) > max)max = *(CH + i);
			}
			cout << max << endl;
		}
	}
}