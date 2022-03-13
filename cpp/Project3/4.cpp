#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Point
{
	double x, y;
public:
	Point():x(0),y(0) { cout << "Constructor." << endl; };
	void setP(double _x, double _y) { x = _x; y = _y; };
	Point(double x_value, double y_value) :x(x_value), y(y_value) 
	{
		cout << "Constructor."<<endl;
	};
	Point(Point& p)
	{
		x = p.x;
		y = p.y;

	}
	~Point() { cout << "Distructor." << endl; };
	double getX() { return y; };
	double getY() { return y; };
	double getDisTo(const Point& p)
	{
		double dis;
		dis = sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
		return dis;
	}

};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		Point **p = new Point*[n];
		for (int i = 0; i < n; i++)
		{
			double x, y;
			cin >> x >> y;
			p[i] = new Point(x, y);
		}
		double longest=0;
		int i1=0, j1=0;
		for(int i=0;i<n;i++)
			for (int j = i; j < n; j++)
			{
				if (longest < p[i]->getDisTo(*p[j]))
				{
					i1 = i; j1 = j;
					longest = p[i]->getDisTo(*p[j]);
				}
			}
		cout << fixed << setprecision(2) << "The longeset distance is " <<longest<< ",between p["
			<< i1 << "] and p[" << j1 << "]." << endl;
		for (int i = 0; i < n; i++)
			delete p[i];
		delete[]p;
	}
}