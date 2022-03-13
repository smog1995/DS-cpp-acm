#include <iostream>
#include <algorithm>
#include <cmath> 
#include <queue>
#include <map>
#include <string>
using namespace std;
const int row = 3;
const int maxx = 9;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
string m = "ulrd";
struct Puzzle
{
	int space;
	int f[maxx];

	string path;
	/*
		bool operator<(const Puzzle &p)
		{
			for(int i=0;i<maxx;i++)
				if(f[i]!=p.f[i])
					return f[i]>p.f[i];
			return false;
		}
		*/
};
bool operator<(const Puzzle& p1, const Puzzle &p)
{
	for (int i = 0; i < maxx; i++)
		if (p1.f[i] != p.f[i])
			return p1.f[i] > p.f[i];
	return false;
}
bool isTarget(Puzzle& p)
{
	for (int i = 0; i < maxx - 1; i++)
		if (p.f[i] != (i + 1)) return false;
	return true;
}
string bfs(Puzzle s)
{
	queue<Puzzle> Q;
	map<Puzzle, bool> V;
	Puzzle u, v;
	s.path = "";
	Q.push(s);
	V[s] = true;

	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();
		if (isTarget(u))
			return u.path;
		int sx = u.space / row;
		int sy = u.space%row;
		for (int r = 0; r < 4; r++)
		{
			int tx = sx + dx[r];
			int ty = sy + dy[r];
			if (tx < 0 || ty < 0 || tx >= row || ty >= row)
				continue;
			v = u;//不能改变根节点值，所以用v来保存根节点，就可以直接改v了 
			swap(v.f[v.space], v.f[tx*row + ty]);
			v.space = tx * row + ty;
			if (!V[v])
			{
				V[v] = true;
				v.path += m[r];
				Q.push(v);
			}
			
		}
	}
	return "unsolveable";
}
int main()
{
	Puzzle s;
	for (int i = 0; i < maxx; i++)
		cin >> s.f[i];
	for (int i = 0; i < maxx; i++)
	{
		if (s.f[i] == 0) s.space = i;
	}

	string ss = bfs(s);
	cout << ss.length()<<endl;
}







