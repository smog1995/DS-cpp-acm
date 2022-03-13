#include <iostream>
using namespace std;
class Complex
{
	float Real, Image;
public:
	Complex(float x = 0, float y = 0) { Real = x; Image = y; };
	Complex(double x) { Real = x; Image = 0; };
	friend Complex operator+(Complex&, Complex&);
	friend Complex operator-(Complex&, Complex&);
	friend Complex operator*(Complex&, Complex&);
	friend Complex operator+(double, Complex&);
	friend Complex operator+(Complex&, double);
	void show() { cout << "Real=" << Real << " Image=" << Image << endl; };
};
Complex operator+(Complex& c1, Complex& c2)
{
	Complex c;
	c.Image = c1.Image + c2.Image;
	c.Real = c1.Real + c2.Real;
	return c;
}
Complex operator+(Complex& c1, double d)
{
	Complex c;
	c.Image = c1.Image ;
	c.Real = c1.Real + d;
	return c;
}
inline Complex operator+(double d, Complex& c2)
{
	return c2 + d;
}
Complex operator-(Complex& c1, Complex& c2)
{
	Complex c;
	c.Image = c1.Image - c2.Image;
	c.Real = c1.Real - c2.Real;
	return c;
}
Complex operator*(Complex& c1, Complex& c2)
{
	Complex c;
	c.Image = c1.Image * c2.Real+c1.Real*c2.Image;
	c.Real = c1.Real*c2.Real - c1.Image*c2.Image;
	return c;
}
int main()
{
	int r1, i1, r2, i2;
	cin >> r1 >> i1 >> r2 >> i2;
	Complex c1(r1, i1), c2(r2, i2),c3;
	(c1 + c2).show();
	(c1 - c2).show();
	(c1 * c2).show();
	c3 = 5.2 + c2;
	c3 = c2 + 5.2;
	c3.show();
}