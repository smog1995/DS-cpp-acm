#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		for (int i1 = 0; i1 < num; i1++)
		{
			int value;
			cin >> value;
			m[value] = i;//该组元素映射 为第i组 
		}
	}
	queue<int> Q[200];
	int queuen = n;
	queue<int> q;
	string str;

	while (cin >> str && str != "STOP")
	{
		if (str == "ENQUEUE")
		{
			int x;
			cin >> x;
			for (int i = 0; i < 200; i++)
			{
				if (m[Q[i].front()] == m[x])
				{
					Q[i].push(x);
					break;
				}
				else if (Q[i].empty())
				{
					queuen++;
					Q[i].push(x);
					break;
				}
			}

		}
		else
		{
			for (int i = 0; i < queuen; i++)
			{
				if (!Q[i].empty())
				{
					q.push(Q[i].front());
					Q[i].pop();
					break;
				}
			}
		}
	}
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}

}