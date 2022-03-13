#include <iostream>
using namespace std;
int tn=1;
class Television
{
	static int TVnum,DVDnum;
	int channel;
	int volume,type;
public:
	Television() :channel(tn++), type(1), volume(50) { TVnum++; };
	friend void set(Television& t, int k, int x, int v);
	static void show();
	void print();
	static void setTVnum(int n) { Television::TVnum += n; };
	static void setDVDnum(int n) { Television::DVDnum += n; };
	static int getTVnum() { return Television::TVnum; };
	static int getDVDnum() { return Television::DVDnum; };

};
void Television::show()
{
	cout << "播放电视的电视机数量为" << Television::getTVnum() << endl;
	cout << "播放DVD的电视机数量为" << Television::getDVDnum()<< endl;
}
int Television::TVnum = 0;
int Television::DVDnum = 0;
void Television::print()
{
	if (type == 1)
		cout << "TV";
	else if (type == 2)
		cout << "DVD";
	cout << "模式--频道" << channel << "--音量" << volume << endl;
}
void set(Television& t, int k, int x, int v)
{
	t.channel = x;
	t.volume += v;
	if (t.volume < 0) t.volume = 0;
	else if (t.volume > 100) t.volume = 100;
	if (k == 2&&t.type!=k)
	{
		Television::setTVnum(-1);
		Television::setDVDnum(1);
	}
	else if (k == 1 && t.type != k)
	{
		Television::setTVnum(1);
		Television::setDVDnum(-1);
	}
	t.type = k;
}
int main()
{
	int n,t;
	cin >> n>>t;
	Television *T = new Television[n];
	while (t--)
	{
		int index,k,x,v;
		cin >> index>>k>>x>>v;
		
		set(T[index - 1], k, x, v);
		cout << "第" << index << "号电视机--";
		T[index - 1].print();
	}
	Television::show();
}