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
	cout << p1;//��1����p1����++�������
	p1--;//�ָ�ԭֵ
	p2 = p1++;
	cout << p2;//�ڶ���p1����++ͬʱ���Ƹ�p2��p2���
	p1--;//�ָ�ԭֵ
	p2 = ++p1;//ǰ��p1,��p2����p1����ֵ�������p1��ǰֵ(�������++p1)
	cout << p2;//�������++p1
	cout << p1;//������
	p1--;//�ָ�ԭֵ
	p1--;
	cout << p1;//������p1����--,�����
	p1++;//�ָ�ԭֵ
	cout << p1;
	p2 = --p1;//ǰ��--
	cout << p2;
	cout << p1;
}