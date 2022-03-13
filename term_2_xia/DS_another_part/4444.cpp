#include <iostream>
#include <stack>
using namespace std;
class Step
{
public:
	int dir;
	int data;
	int flag;
	Step() {
		dir = 1;
		flag = 0;
	}
};
void NextPos(Step& M, int& px, int& py)
{

	if (M.dir == 1)	px++;
	else if (M.dir == 2)	py++;
	else if (M.dir == 3)	px--;
	else if (M.dir == 4)	py--;

}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		stack<int> path;
		int n;
		int curx = 0, cury = 0;
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
		do {
			if (!M[px][py].data || px >= n || py >= n || px < 0 || py < 0)//||px>=n||py>=n||px<0||py<0
			{
				M[px][py].data = 1;//留下足迹
			//	if (px - 1 != 0 || py - 1 != 0 || px + 1 != n || py + 1 != n)
			//	{

				path.push(px); path.push(py);
				//NextPos(M[px][py], px, py);
				//M[px][py].dir++;
		//	}
				if (px == n - 1 && py == n - 1) break;
				px++;
				//NextPos(M[px][py], px, py);
			}
			//0 0 1
			//1 0 0
			//0 0 0
			else if (M[px][py].data)
			{
				if (!path.empty())
				{
					py = path.top(); path.pop();
					px = path.top(); path.pop();
					if (M[px][py].dir < 4)
					{
						M[px][py].dir++;
						//if (px - 1 != 0 || py - 1 != 0 || px + 1 != n || py + 1 != n)
						//{
						path.push(px); path.push(py);
						NextPos(M[px][py], px, py);

						//}
					}
					while (M[px][py].dir == 4 && !path.empty())
					{
						M[px][py].data = 1;
						py = path.top(); path.pop();
						px = path.top(); path.pop();
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
