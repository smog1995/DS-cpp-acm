#include <iostream>
using namespace std;
//int gcd(int a,int b)
//{
////	if(a<b) 
////	{
////		int x=a;
////		a=b;
////		b=x;
////	}
//	if(b==0) return a;
//	return gcd(b,a%b);
// } 
class Fraction
{
	int numerator,denominator;
//	int common_divisor();
//	void contracted();
	public:
		Fraction(int n,int d);
		Fraction(Fraction&);
		friend Fraction operator+(Fraction&,Fraction&);
		friend Fraction operator-(Fraction&,Fraction&);
		friend Fraction operator*(Fraction);
		friend Fraction operator/(Fraction);
		void Set(int n=0,int d=1);
		void disp(){cout<<"fraction="<<numerator<<"/"<<denominator<<endl;};
 };
Fraction::Fraction(int n,int d)
{
	numerator=n;
	denominator=d;
}
Fraction::Fraction(Fraction& f)
{
	numerator=f.numerator;
	denominator=f.denominator;
}
Fraction Fraction::operator*(Fraction f)
{
	Fraction F(numerator,denominator);
	F.numerator*=f.numerator;
	F.denominator*=f.denominator;
	return F;
}
Fraction Fraction::operator/(Fraction f)
{
	Fraction F(numerator,denominator);
	F.numerator*=f.denominator;
	F.denominator*=f.numerator;
	return F;
}
Fraction Fraction::operator+(Fraction f)
{
	Fraction F(numerator,denominator);
	F.numerator=(F.numerator*f.denominator)+(f.numerator*F.denominator);
	F.denominator*=f.denominator;
	return F;
}
Fraction Fraction::operator-(Fraction f)
{
	Fraction F(numerator,denominator);
	F.numerator=(F.numerator*f.denominator)-(f.numerator*F.denominator);
	F.denominator*=f.denominator;
	return F;
}
void Fraction::Set(int n,int d)
{
	numerator=n;
	denominator=d;	
}
int main()
{
	int n,d,n1,d1;
	cin>>n>>d>>n1>>d1;
	Fraction f1(n,d);
	Fraction f2(n1,d1);
	(f1+f2).disp();
	(f1-f2).disp();
	(f1*f2).disp();
	(f1/f2).disp();
}
