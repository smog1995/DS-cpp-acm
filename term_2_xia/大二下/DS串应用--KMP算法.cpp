#include<iostream>
#include <string>
using namespace std;
class myString {
private:
	string mainstr;
	int size;
	void GetNext(string p, int nexxt[]);
	int KMPFind(string p, int pos, int next[]);
public:
	myString();
	~myString();
	void SetVal(string sp);
	int KMPFindSubstr(string p, int pos);
};
void myString::GetNext(string p, int next[])
{
	int i = 0, j = -1;
	
	int len = p.length();
	next[0] = -1;
	while (i < len)
	{
		if (j == -1 || p[i] == p[j]) {
			j++; i++; next[i] = j;
		}
		else j = next[j];
	}
}
int myString::KMPFind(string p, int pos, int next[])
{
	int i = -1, j = -1;
	int len1 = mainstr.length(),len2=p.length();
	while (i < len1&&j < len2)
	{
		if (j == -1 || mainstr[i] == p[j])
		{
			i++; j++;
		}
		else j = next[j];
	}
	if (j >= len2) return i - len2+1;
	return 0;
}
myString::myString()
{
	size = 0;
	mainstr = "";
}
myString::~myString()
{
	size = 0;
	mainstr = "";
}
void myString::SetVal(string sp)
{
	mainstr = "";
	mainstr.assign(sp);
	size = mainstr.length();
}
int myString::KMPFindSubstr(string p, int pos)
{
	int L = p.length();
	int *next = new int[L+1];
		GetNext(p, next);
	for (int i = 0; i < L; i++)
		cout << next[i] << " ";
	cout << endl;
	int v = -1;
	v = KMPFind(p, pos, next);
	delete[]next;
	return v;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		myString ms;
		string sp, s;
		cin >> sp >> s;
		ms.SetVal(sp);
		cout<<ms.KMPFindSubstr(s,0)<<endl;
	}
}