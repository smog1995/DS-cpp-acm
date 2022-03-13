#include <iostream>
using namespace std;

int max(int x, int y)
{
	return x > y ? x : y;
}
const int r = 7, l = 6;
char X[r + 1] = { "abcbdab" };
char Y[l + 1] = { "bdcaba" };

void Sequence(char *B[l+1], int i, int j)
{
	if (getchar() == 'a')
	if (i = 0 && j == 0);
	 if (*B[i*l+j]== 'y')
	{
		 cout << "aaa";
		cout << X[i - 1];
		Sequence(B, i - 1, j - 1);
	}
	else if (*B[i*l + j] == 'u') Sequence(B, i - 1, j);
	else if (*B[i*l + j] + j == 'l')Sequence(B, i, j -1);
}
int main()
{

	int C[r+1][l+1];
	char **B;
	B = new char*[r + 1];
	for (int i = 0; i < r + 1; i++)
		B[i] = new char[l + 1];

	for (int i = 0; i <= r; i++)
		for (int i1 = 0; i1 <= l; i1++)
		{
			C[i][i1] = 0;
			B[i][i1] = '\0';
		}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= l; j++)
		{
			
			if (X[i - 1] != Y[j - 1])
			{
				C[i][j] = max(C[i - 1][j], C[i][j - 1]);
				if (C[i][j] == C[i - 1][j]) B[i][j] = 'u';
				else B[i][j] = 'l';
			}
			else if (X[i - 1] == Y[j - 1])
			{
				C[i][j] = C[i - 1][j - 1] + 1;
					B[i][j] = 'y';
			}
		}
	}
	Sequence(B, r, l);
	for (int i = 0; i <= r; i++)
	{
		for (int i1 = 0; i1 <= l; i1++)
			cout << C[i][i1] << " ";
		cout << endl;
	}
	for (int i = 0; i <= r; i++)
	{
		for (int i1 = 0; i1 <= l; i1++)
			cout << B[i][i1] << " ";
		cout << endl;
	}
	if(getchar()=='a')
	Sequence(B,r,l);
	Sequence(B, r, l);
}