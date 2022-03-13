#include <iostream>
#include <string>
using namespace std;
void get_next(string T, int *next)
{
	int i = 0,j=-1;
	next[0] = -1;
	int len =T.length();
	while (i < len)
	{
		if (j == -1 || T[j] == T[i]) { i++; j++; next[i] = j; }
		else j = next[j];
	}
	/*
	for (int i = 1; i <= len+1; i++)
		cout << next[i] << " ";
	cout << endl;
	*/
}
int main() {
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		int *next = new int[str.length()+1];
		get_next(str, next);
		int max = next[str.length()];
		if (max < 1) cout << "empty" << endl;
		else {
			for (int i = 0; i < max ; i++)
				cout << str[i];
			cout << endl;
		}
		
	}
}