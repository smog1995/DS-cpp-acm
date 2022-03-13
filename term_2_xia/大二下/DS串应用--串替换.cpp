#include <iostream>
#include <string>
using namespace std;
void get_next(string &T, int *next)
{
	int i = 0, j = -1;
	next[0] = -1;
	int len = T.length();
	while (i<len)
	{
		if (j == -1 || T[i] == T[j]) { i++; j++; next[i] = j; }
		else j = next[j];
	}
	
}

int BF(string S, string T)
{
	int len1 = S.length(), len2 = T.length();
	int j = 0, i = 0;
	while (i < len1&&j < len2)
	{
		if (S[i] == T[j]) { i++; j++; }
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == len2) return i - len2;
	return -1;
}

int KMP(string S, string T,int pos)
{
	int len1 = S.length(),len2=T.length();
	int j = -1, i =pos-1;
	int *next = new int[len2+1];
	get_next(T, next);
	while (i < len1 && j < len2)
	{
		if (j==-1|| S[i] == T[j]) { i++; j++; }
		else j = next[j];
	}
	if (j >= len2) return i - len2;
	else return -1;
}
void replace(string &s, string &t,string &v)
{
	int len1 = s.length(), len2 = t.length(),len3=v.length();
	int pos = KMP(s, t,0);
//	cout << pos << endl;
	if (pos==-1)
	{
		cout << s << endl;
		return;
	}
	string s1;

	if (pos == 0)
	{
		s1 += v;
		s1 += s.substr(pos + len2, len1 - 1);
		
	}
	else {
		s1 += s.substr(0, pos );
		s1 += v;
		s1 += s.substr(pos + len2, len1 - 1);
	}
	/*
	//int pos = BF(s, t);
	if (pos == -1) 
	{	
		cout << s << endl;
		return; 
	}
	if (len2 == len3)
	{
		for (int i = pos, j = 0; j < len3; i++,j++)
			s[i] = v[j];
	}
	else if (len2 < len3)
	{
		if (s.size() < len1 + len3)
		{
			if (s.capacity() < len1 + len3) {
				s.reserve((len1 + len3) * 2);
			}
			s.resize((len1 + len3) + 1);
			//cout << s.size() << endl;
		}
		//先将字符串往后移动
		for (int i = len1; i >= pos; i--)
			s[i + len3-len2] = s[i];
		for (int i = pos, j = 0; j < len3; i++, j++)
			s[i] = v[j];

	}
	else if (len2 > len3)
	{
		//先将字符串往前挪动
		for (int i = pos; i < len1-(len2 - len3); i++)
			s[i] = s[i+ (len2 - len3)];
		s.resize(len1 - (len2 - len3));
		for (int i = pos, j = 0; j < len3; i++, j++)
			s[i] = v[j];
		
		
	}*/
	cout << s1 << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		string t, v;
		cin >> t >> v;
		cout << str << endl;
		replace(str, t, v);
	}
}