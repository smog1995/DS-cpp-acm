#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		int len1 = str.length();
		int max = 0;
		int index=0;
		for (int i = 0; i <len1; i++)
		{
			for (int j = i + 1; j < len1;j++)
			{
				string str1 = str.substr(i, j);
				string str2 = str.substr(j, len1 - 1);
				index = str2.find(str1);
				if (index != string::npos&&max<str1.length()) {
					max = str1.length();
				}
			}
		}
		if(max)
		cout << max << endl;
		else cout << -1 << endl;
	}
}