#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		double x;
		cin >> x;
		double low = 0, high = x;
		double mid;
		while (low < high)
		{
			mid = low + (high - low) / 2;
			if (fabs(mid*mid - x) < 1e-5) {
				cout << setprecision(4) << mid << endl;
				break;
			}
			else if ((mid*mid) > x) high = mid;
			else low = mid;
		}
		if (high - low < 1e-6) cout << "error" << endl;
	}
}