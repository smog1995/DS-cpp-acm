#include <queue>
#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int durance;

};
int main() {
	int n;
	cin >> n;
	queue<int> Q[3];
	char  *s=new char[n];
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		getchar();
	}

	for (int i = 0; i < n; i++)
	{
		int time;
		cin >> time;
		if (s[i] == 'A') Q[0].push(time);
		else if (s[i] == 'B') Q[1].push(time);
		else Q[2].push(time);
	}
	for (int i = 0; i < 3; i++)
	{
		int average = 0,num=0;
		while (!Q[i].empty())
		{
			average += Q[i].front();
			Q[i].pop();
			num++;
		}
		average /= num;
		cout << average << endl;
	}
}