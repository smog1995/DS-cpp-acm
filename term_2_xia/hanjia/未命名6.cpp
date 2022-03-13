#include <iostream>
#include <string>
#include <map> 
using namespace std;
string m="ulrd";
int maxx=9;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
struct Puzzle
{
	string path;
	int f[maxx];
	
}
bool isTarget(const Puzzle& p)
{
	for(int i=0;i<maxx-1;i++)
	if(p.f[i]!=(i+1))return false;
	return true;
}
bool operator<(const Puzzle& p,const Puzzle& p1)
{
	for(int i=0;i<maxx;i++)
	if(p.f[i]!=p1.f[i]) return p.f[i]>p1.f[i];//
	return false;//µÈÓÚ 
}
string bfs(Puzzle& p)
{
	queue<Puzzle> Q;
	map<Puzzle,bool> m;
	m.push(p);
	Q.push(p);
	while(!Q.empty())
	{
		for(int r=0;r<4;r++)
		{
			
		}
	}
}
