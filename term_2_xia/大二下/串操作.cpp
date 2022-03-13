#include <iostream>
using namespace std;
int Maxsize = 1000;
class HString {
public:
	int length;
	char *ch;
	HString(): {
		length = 0;
		ch = new char[Maxsize];
	}
	int Length() { return length; }
	void Concat(HString &S)
	{
		if (S.length + length >= Maxsize)
		{
			Maxsize *= 2;
			char *ch1 = new char[Maxsize];
			for (int i = 0; i < S.length+length;i++)
			ch1[i] = i < length ? ch[i] : ch1[i];
			delete[] ch;
			ch = ch1;
		}
		else {
			for (int i = 0, i1 = length; i < S.length; i++, i1++)
				ch[i1] = S.ch[i];
			
		}
		length += S.length;
	}
	friend bool Compare(HString &S, HString &T);
	int SubString(HString &Sub,int pos,int len)
	{
		if (pos<1 || pos>length ||len<0|| len > length - pos + 1)
			return -1;
		if (!len) {
			S.ch = NULL;
			S.length = 0;
		}
		else {
			Sub.ch = new char[len];
			for (int i = pos - 1, i1 = 0; i < len; i1++, i++)
				Sub.ch[i1] = ch[i];
			Sub.length = len;
		}
	}
	void Replace(HString &Substr,HString &V)
	{
		for (int n = 0, i = 0; i <= length - Substr.length; i++)
		{
			for (int j = i, k = 0; Substr.ch[j] == ch[k]; j++, k++)
			{
				if (k > Substr.length)
				{
					if (Substr.length == V.length) {//新子串长度与原子串长度相同时可以直接替换
						for (int l = 0; l < Substr.length; l++)
							ch[i + l] = V.ch[l];
					}
					else if (Substr.length < V.length) {//顺序表的插入
						for (int l = Substr.length; l >= i; l--)
						{
							
						}
						for (int i = length; i >= index; i--)
							a[i] = a[i - 1];
					}
				}
			}
		}
	}
};
bool Compare(HString &S, HString &T)
{
	for (int i = 0; i < S.length&&i < T.length; i++)
		if (S.ch[i] != T.ch[i]) return S.ch[i] - T.ch[i];//比较到哪里不相等时，返回的是当前字符哪个大哪个小
	return S.length - T.length;//字符串1比字符串2长则返回正，否则为负
}
