#include <iostream>
using namespace std;

class Metal
{
	int	H, V, W;
public:
	Metal(int h, int w, int v) :H(h), W(w), V(v) {};
	Metal() {};
	void print()
	{
		cout << "硬度" << H << "--重量" << W << "--体积" << V << endl;
	};
	friend Metal operator+(Metal& m1, Metal& m2);
	friend Metal operator*(Metal& m,int n);
	Metal& operator++();
	Metal& operator--(int);

};
Metal operator+(Metal& m1, Metal& m2)
{
	Metal m;
	m.H = m1.H + m2.H;
	m.V = m1.V + m2.V;
	m.W = m1.W + m2.W;
	return m;
}
Metal operator*(Metal& m,int n)
{
	Metal m1;
	m1.V =m.V* n;
	m1.H = m.H;
	m1.W = m.W;
	return m1;
}
Metal& Metal::operator++()
{
	this->H++;
	this->W += this->W * 0.1;
	this->V += this->V *0.1;
	return *this;
}
Metal& Metal::operator--(int)
{
	Metal m = *this;
	this->H--;
	this->W -=this->W* 0.1;
	this->V -= this->V* 0.1;
	
	return m;
}
int main()
{
	int m1h, m2h, m1w, m2w, m1v, m2v;
	cin >> m1h >> m1w >> m1v >> m2h >> m2w >> m2v;
	int n;
	cin >> n;
	Metal m1(m1h, m1w, m1v), m2(m2h, m2w, m2v);
	(m1 + m2).print();
	(m1*n).print();
	(++m1).print();
	m2--;
	m2.print();
}
