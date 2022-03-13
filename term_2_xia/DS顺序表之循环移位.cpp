#include <iostream>
using namespace std;
void circle(int* L, int *L1,int n)
{
	int turn, num;
	cin >> turn >> num;
	if (turn == 0)
		for (int i = 0; i < n; i++)
			L1[i] = L[(i - num + n - 1) % n];
	else
		for (int i = 0; i < n; i++)
			L1[i] = L[(i + num + n - 1) % n];
	for (int i = 0; i < n; i++)
		cout << L1[i] << " ";
	cout << endl;
}
int main()
{
	int n;
	cin >> n;
	int *L = new int[n];
	int *L1 = new int[n];
	for (int i = 0; i < n; i++)
		cin >> L[i];
	for (int i = 0; i < n; i++)
		cout << L[i] << " ";
	cout << endl;
	circle(L, L1, n);
	circle(L, L1, n);
}