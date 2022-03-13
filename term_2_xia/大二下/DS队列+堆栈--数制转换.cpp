#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
void zstransform(int zs, stack<char> &s, int jz)
{
	while (zs)
	{
		int x;
		x = zs % jz;
		if(x>=10)
		switch (x) {
			case 10:s.push('A'); break;
			case 11: s.push('B'); break;
			case 12: s.push('C'); break;
			case 13: s.push('D'); break;
			case 14: s.push('E'); break;
			case 15: s.push('F'); break;
		}
		else {
			s.push(x + '0');
		}
		zs /= jz;
	}
}
void xstransform(double xs, queue<char> &q, int jz)
{
	int num = 3;
	int x;
	while (num--)
	{
		xs *= jz;
		int x=xs;
		if (x >= 10)
		{
			switch (x) {
			case 10:q.push('A'); break;
			case 11: q.push('B'); break;
			case 12: q.push('C'); break;
			case 13: q.push('D'); break;
			case 14: q.push('E'); break;
			case 15: q.push('F'); break;
			}
		}
		else q.push('0' + x);
		xs-=(int)xs;
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		double x;
		int jz;
		cin >> x >> jz;
		stack<char> s;
		queue<char> q;
		int zs = x;
		double xs = x - zs;
		zstransform(zs, s, jz);
		xstransform(xs, q, jz);
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
		cout << ".";
		while (!q.empty())
		{
			cout << q.front();
			q.pop();
		}
		cout << endl;
	}
}