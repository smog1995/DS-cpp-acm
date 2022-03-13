#include <iostream>
using namespace std;
class RMB
{
	int y, j, f;
public:
	RMB(double r);
	friend ostream& operator<<(ostream& stream,RMB&);
};
ostream& operator<<(ostream& stream,RMB& r)
{
	stream << "yuan=" << r.y << " "
		<< "jiao=" << r.j << " "
		<< "fen=" << r.f << " " << endl;
	return stream;
}


RMB::RMB(double r)
{
	y = r;
	j = (int)(r * 10) % 10;
	f = (int)(r * 100) % 10;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		double r;
		cin >> r;
		RMB R(r);
		cout << R;
	}
}

