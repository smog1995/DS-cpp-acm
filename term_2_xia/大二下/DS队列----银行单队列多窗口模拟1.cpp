#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;
class Event {
public:
	int endurance, start;
	Event(){}
	Event(int e,int s):endurance(e),start(s){}
};

int main()
{
	int n;
	cin >> n;
	queue<Event> q;
	for (int i = 0; i < n; i++)
	{
		int e, s;
		cin >> s>> e;
		Event E(e,s);
		q.push(E);
	}
	int k;
	cin >> k;
	int *final = new int[k];
	int maxwaitt = 0;
	double average = 0;
	for (int i = 0; i < k; i++) final[i] = 0;
	while (!q.empty())
	{
		Event e = q.front();
		int min=0;
		for (int i = 1; i < k; i++)
		{
				if (final[i] <final[min]) {
					min = i;
				}
		}
		if (e.start >= final[min]) final[min] = e.endurance + e.start;
		else
		{
			int waittime = final[min] - e.start;
			average += waittime;
			final[min] +=  e.endurance;
			if (waittime > maxwaitt) maxwaitt = waittime;
		}
		q.pop();
	}
	int max = 0;
	for (int i = 1; i < k; i++)
		if (final[i] > final[max]) max = i;
	cout << fixed << setprecision(1) << average / n << " " << maxwaitt << " " << final[max] << endl;
}