#include <iostream>
#include <string>
#define LL long long int
using namespace std;
char words[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
int gcd(int a, int b)
{
	if (a < b) {
		int t = a;
		a = b;
		b = t;
	}
	if (b == 0) return a;
	int r;
	while ((r = a % b) != 0)
	{
		a = b;
		b = r;
	}
	return b;
}
LL exgcd(LL a, LL b, LL &x, LL &y)//扩展欧几里得算法 
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	LL ret = exgcd(b, a%b, y, x);
	y -= a / b * x;
	return ret;
}
LL getInv(int a, int mod)//求a在mod下的逆元，不存在逆元返回-1 
{
	LL x, y;
	LL d = exgcd(a, mod, x, y);
	return d == 1 ? (x%mod + mod) % mod : -1;
}

int main()
{
	
	int k1=11, k2=6;
	int k3=1;

	if (gcd(k1, k2) == 1)
	{
		while ((k3*k1) % 26 != 1) k3++;//求逆元k3
		cout << "k3为" << k3 << endl;
		char m[8] = "sorcery";
		cout <<"所输入的明文："<< m << endl;
		char code[8],decode[8];
		int Im[7],Ic[7];
		for (int i = 0; i < 7; i++)
		{
			Ic[i] = (k1*(m[i] - 'a') + k2) % 26;//求出密文对应的数字
			code[i] = Ic[i] + 'A';//将数字转化为字母
		}
		code[7] = '\0';
		cout <<"密文为" <<code << endl;

		for (int i = 0; i < 7; i++)
		{
			Im[i] = (k3 % 26) * (Ic[i] +(26-k2)%26) % 26;
			decode[i] = Im[i] + 'a';
		}
		decode[7] = '\0';
		cout << "译码所得的明文为"<<decode << endl;
	}
	
	/*
	string str = "FMXVEDKAPHFERBNDKRXRSREFMORUDSDKDVSHVUFEDKAPRKDLYEVLRHHRH";
	//string str = "VNYQVEVYCYUHE";
	cout << "原字符串：" << str << endl;
	int len = str.length();
	int *a = new int[26];
	int max[5] = { 0 };
	for (int i = 0; i < 26; i++)
		a[i] = 0;
	for (int i = 0; i < len; i++)
	{
		a[str[i] - 'A'] += 1;
	}//统计字母出现频率
	int i = 1, j = 0;
	for (int k = 0; k < 25; k++) {
		if (a[j] < a[i]) {
			max[0] = words[i] - 'A';
			j = i;
		}
		i++;
	}

	i = 1, j = 0;
	for (int k = 0; k < 25; k++) {
		if (a[j] < a[i]) {
			if ((words[i] - 'A') != max[0]) {
				max[1] = words[i] - 'A';
				j = i;
			}
		}
		i++;
	}


	i = 1, j = 0;
	for (int k = 0; k < 25; k++) {
		if (a[j] < a[i]) {
			if ((words[i] - 'A') != max[0] && (words[i] - 'A') != max[1]) {
				max[2] = words[i] - 'A';
				j = i;
			}
		}
		i++;
	}

	i = 1, j = 0;
	for (int k = 0; k < 25; k++) {
		if (a[j] < a[i]) {
			if ((words[i] - 'A') != max[0] && (words[i] - 'A') != max[1] && (words[i] - 'A') != max[2]) {
				max[3] = words[i] - 'A';
				j = i;
			}
		}
		i++;
	}

	i = 1, j = 0;
	for (int k = 0; k < 25; k++) {
		if (a[j] < a[i]) {
			if ((words[i] - 'A') != max[0] && (words[i] - 'A') != max[1] && (words[i] - 'A') != max[2] && (words[i] - 'A') != max[3]) {
				max[4] = words[i] - 'A';
				j = i;
			}
		}
		i++;
	}
	int k1 = 0, k2 = 0, h = 1;
	while (gcd(k1, 26) != 1)
	{
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (((4 * i + j) % 26) == ((int)max[0]) && ((19 * i + j) % 26) == ((int)max[h]))
				{
					k1 = i;
					k2 = j;
					h++;
					break;
				}
			}
		}
	}
	int k3 = getInv(k1, 26);
	cout << "所求得的k1和k2为：";
	cout << k1 << " " << k2 << " " << endl;
	cout << "所求k3为：" << k3 << endl;
	string str1(str.length(), 'a');
	for (int i = 0; i < str.length(); i++)
	{
		//Im[i] = (k3 % 26) * (Ic[i] + (26 - k2) % 26) % 26;
		str1[i] = ((k3 % 26)*((str[i] - 'A') + (26 - k2) % 26) % 26) + 'a';
	}
	cout << "解密后的密码为：" << str1 << endl;
	string str2(str1.length(), 'a');
	for (int i = 0; i < str2.length(); i++)
	{
		//Ic[i] = (k1*(m[i] - 'a') + k2) % 26;//求出密文对应的数字
		str2[i] = (k1*(str1[i] - 'a') + k2) % 26 + 'A';
	}
	cout << "恢复，加密后为：" << str2 << endl;
	*/

}