#include <iostream>
using namespace std;
int main()
{
	char **month;
	char Month[12][10] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	month = new char*[12];
	for (int i = 0; i < 12; i++)
	{
		month[i] = &Month[i][0];
	}
	int t;
	cin >> t;
	while (t--)
	{
		int x;
		cin >> x;
		if(x<=12&&x>=0)
		cout << month[x - 1] << endl;
		else cout << "error" << endl;
	}
}