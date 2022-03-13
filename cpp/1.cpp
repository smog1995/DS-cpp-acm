#include <iostream>
using namespace std;
class Point {
	int x, y, z;
public:
	Point(int x1=0, int y1=0, int z1=0) :x(x1), y(y1), z(z1) {};
	friend Point operator++(Point&);
	friend Point operator++(Point&, int);
	friend Point operator--(Point&);
	friend Point operator--(Point&, int);
	friend ostream& operator<<(ostream& , Point&);
};
ostream& operator<<(ostream& stream, Point& p)
{
	stream << "x=" << p.x << " "
		<< "y=" << p.y << " "
		<< "z=" << p.z << " " << endl;
	return stream;
}
Point operator++(Point& p)
{
	p.x += 1;
	p.y += 1;
	p.z += 1;
	return p;
}
Point operator++(Point& p, int)
{
	Point np=p;
	p.x += 1;
	p.y += 1;
	p.z += 1;
	return np;
}
Point operator--(Point& p)
{
	p.x -= 1;
	p.y -= 1;
	p.z -= 1;
	return p;
}
Point operator--(Point& p,int)
{
	Point np = p;
	p.x -= 1;
	p.y -= 1;
	p.z -= 1;
	return np;
}
int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	Point p1(x, y, z);
	Point p2;
	p1++;
	cout << p1;//第1行是p1后置++后，再输出
	p1--;//恢复原值
	p2 = p1++;
	cout << p2;//第二行p1后置++同时复制给p2，p2输出
	p1--;//恢复原值
	p2 = ++p1;//前置p1,用p2储存p1返回值用来输出p1当前值(代替输出++p1)
	cout << p2;//代替输出++p1
	cout << p1;//三四行
	p1--;//恢复原值
	p1--;
	cout << p1;//第五行p1后置--,再输出
	p1++;//恢复原值
	cout << p1;
	p2 = --p1;//前置--
	cout << p2;
	cout << p1;
}