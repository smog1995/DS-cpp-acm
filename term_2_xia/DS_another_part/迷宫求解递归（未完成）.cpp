#include <iostream>
#include <stack>
using namespace std;
 	int n;
void res(int** a,int x,int y,stack<int> &s,int &f)
{
	if(f) return ;
	if(x>=0&&y>=0&&x<n&&y<n&&a[x][y]==0) 
	{
		s.push(x);
		s.push(y);
		a[x][y] = 1;
	}
	else{
		if (!s.empty())
		{
			y = s.top();
			s.pop();
			x = s.top();
			s.pop();
		}
	}
	if(x==n-1&&y==n-1) f=1;
	if(!f) res(a,x,y+1,s,f);
	if(!f) res(a,x+1,y,s,f);
	if(!f) res(a,x,y-1,s,f);
	if(!f) res(a,x-1,y,s,f);
	if (!f) {
		s.pop(); s.pop();
	}
 } 
 int main()
 {
 	stack<int> path;
 	int t;
 	cin>>t;

 	cin>>n;
 	int** a=new int*[n];

 	for(int i=0;i<n;i++)
 	 a[i]=new int[n];
 	 for(int i=0;i<n;i++)
 	 for(int i1=0;i1<n;i1++)
 	 	cin>>a[i][i1];
 	 	int f=0;
 	res(a,0,0,path,f);
 	 	stack<int> path1;
 	if (!path.empty())
		{
			while (!path.empty())
			{
				path1.push(path.top());
				path.pop();
				path1.push(path.top());
				path.pop();
			}
			int i = 0;  //以下是输出路径的代码

			while (!path1.empty())

			{
				int xp = path1.top(); path1.pop();
				int yp = path1.top();  path1.pop();
				if ((++i) % 4 == 0)

					cout << '[' << xp << ',' << yp << ']' << "--" << endl;

				else

					cout << '[' << xp << ',' << yp << ']' << "--";


			}

			cout << "END" << endl;
		}
		else

			cout << "no path" << endl;
	}
 
