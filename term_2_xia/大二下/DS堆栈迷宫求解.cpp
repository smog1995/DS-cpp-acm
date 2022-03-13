#include <iostream>
#include <stack>
using namespace std;
class Step
{
public:
	int dir;
	int flag;
	Step() {
		dir = 1;
		flag = 0;
	}
};
void NextPos(Step& M, int& px, int& py)
{

	if (M.dir == 1)	py++;
	else if (M.dir == 2)	px++;
	else if (M.dir == 3)	py--;
	else if (M.dir == 4)	px--;

}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		stack<int> path;
		int n;
		int px = 0, py = 0;
		cin >> n;
		Step **M = new Step*[n];

		for (int i = 0; i < n; i++)
		{
			M[i] = new Step[n];
		}
		for (int i = 0; i < n; i++)
			for (int i1 = 0; i1 < n; i1++)
				cin >> M[i][i1].data;
		if(!M[0][0].data)
		do {
			
			if ( px <n && py < n && px >= 0 && py >= 0 && !M[px][py].data)
			{
				M[px][py].data = 1;//留下足迹
				path.push(px); path.push(py);
				if (px == n - 1 && py == n - 1) break;
				py++;
			}

			else 
			{
				if (!path.empty())
				{
					py = path.top(); path.pop();
					px = path.top(); path.pop();
					while (M[px][py].dir == 4 && !path.empty())//必须在下面的if语句（dir<4）之前，否则加到4就会进入循环
					{
						M[px][py].data = 1;
						py = path.top(); path.pop();
						px = path.top(); path.pop();
					}
					if (M[px][py].dir < 4)
					{
						M[px][py].dir++;
						path.push(px); path.push(py);
						NextPos(M[px][py], px, py);
					}
					
				}
			}
		} while (!path.empty());
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
}