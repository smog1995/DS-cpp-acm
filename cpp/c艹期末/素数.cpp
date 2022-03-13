#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int flag= 0;
	int n;
	cin >> n;
	for (int i = 2; i < sqrt(n); i++)
	{
		if (n%i == 0) flag = 1;
	}
	if (flag == 1) cout << n<<" is not prime" << endl;
	else cout << n << "is prime" << endl;
}