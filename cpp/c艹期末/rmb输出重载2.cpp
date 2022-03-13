#include <iostream>

using namespace std;
class RMB
{
	int y,j,f;
	public:
		RMB(float r)
		{
			y=r;
			j=(int)(r*10)%10;
			f=(int)(r*100)%10;
		}
		friend ostream& operator<<(ostream& s,RMB& r); 
};
ostream& operator<<(ostream& stream,RMB& r)//¼ÇµÃÊÇostream 
{
	stream<<"yuan="<<r.y<<" jiao="<<r.j<<" fen="<<r.f;
	return stream;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		float x;
		cin>>x;
		RMB r(x);
		cout<<r<<endl;
	}
}
