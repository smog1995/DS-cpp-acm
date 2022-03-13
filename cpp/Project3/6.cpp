#include <iostream>
using namespace std;
int main()
{
	int *matrix=new int[2*3];
	int *matrix1=new int[3*2];
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 3; j++)
				cin >> *(matrix + i * 3 + j);
		for(int i = 0; i < 2; i++)
			for (int j = 0; j < 3; j++)
			{
				*(matrix1+ (2-j)* 2 + i) = *(matrix + i*3 + j);
			}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
				cout << *(matrix1 + i * 2 + j) << " ";
			cout << endl;
		}

	}
}