#include <iostream>
#include<algorithm>
#include <string>
using namespace std;
typedef struct test
{
	int number;
	string tm[3];

};
bool compare(string& s1, string& s2)
{
	int x = s1.length(), y = s2.length();
	int sum = 0;
	int length = x < y ? x : y;
	for (int i = 0; i < length; i++)
	{
		if (s1[i] == s2[i]) sum++;
	}
	return sum >= length*0.9;
	
}
int main()
{
	int num,n;
	string t1, t2, t3;
	cin >> n;
	test *t = new test[n];
	for (int i = 0; i < n; i++)
	{
		cin >> num >> t1 >> t2 >> t3;
		t[i].number = num;
		t[i].tm[0] = t1;
		t[i].tm[1] = t2;
		t[i].tm[2] = t3;
	}
	for (int i = 0; i < n; i++)
	{
		for (int i1 = i + 1; i1 < n; i1++)
		{
			for (int i2 = 0; i2 < 3; i2++)
				if (compare(t[i].tm[i2], t[i1].tm[i2])) cout << t[i].number << " " << t[i1].number << " " << i2 + 1<<endl;
		}
	}
}