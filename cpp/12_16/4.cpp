#include <iostream>
#include <memory.h>
using namespace std;
class Vector
{
	int vec[10];
public:
	Vector(int v[10]);
	Vector() {};
	Vector(Vector&);
	Vector operator+(Vector&);
	Vector operator-(Vector&);
	friend ostream& operator<<(ostream&, Vector&);
};
ostream& operator<<(ostream& stream, Vector& v)
{
	for (int i = 0; i < 10; i++)
		stream << v.vec[i] << " ";
	stream << endl;
	return stream;
}
Vector Vector::operator-(Vector& V)
{
	Vector v;
	for (int i = 0; i < 10; i++)
	{
		v.vec[i] = V.vec[i]- vec[i];
	}
	return v;
}
Vector Vector::operator+(Vector& V)
{
	Vector v;
	for (int i = 0; i < 10; i++)
	{
		v.vec[i] = V.vec[i] + vec[i];
	}
	return v;
}
Vector::Vector(int* v)
{
	memcpy(vec, v, sizeof(vec));
}
Vector::Vector(Vector& V)
{
	memcpy(vec, V.vec, sizeof(vec));
}
int main()
{
	int vec1[10], vec2[10];
	for (int i = 0; i < 10; i++)
		cin >> vec1[i];
	for (int i = 0; i < 10; i++)
		cin >> vec2[i];
	Vector v1(vec1), v2(vec2);
	Vector v3;
	v3 = v1 + v2;
	cout << v3;
	v3 = v2 - v1;
	cout << v3;
}