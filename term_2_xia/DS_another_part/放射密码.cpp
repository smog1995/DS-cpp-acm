#include<iostream>
#include<cstring>
#include <string>
using namespace std;
char words[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
//string words = "FMXVEDKAPHFERBNDKRXRSREFMORUDSDKDVSHVUFEDKAPRKDLYEVLRHHRH";

int gcd(int a, int b)  //辗转相除法求a，b的最大公约数 
{
	int k = 0;
	do
	{
		k = a % b;
		a = b;
		b = k;
	} while (k != 0);
	return a;
}
int Ni(int a, int b)  //求a相对b的逆元 
{
	int i = 0;
	while (a * (++i) % b != 1);  //a*i=1 mod b
	return i;
}
void jiemi(string ch, int k1, int k2) {
	int len = ch.length();
	char mm[100];
	for (int i = 0; i < len; i++)
	{
		int t = ch[i] - 65 - k2;
		if (t < 0) t += 26;
		mm[i] = k1 * t % 26 + 65;    //解密公式 x=k1^-1*(e(x)-k2)(mod26)
	}
	cout << "解密后的明文为：";
	for (int i = 0; i < len; i++)
		cout << mm[i];
	cout << endl;
}
void tongji(string ch) {
	int a[100] = { 0 };
	char max[5];
	int len = ch.length();
	for (int i = 0; i < len; i++) {
		a[ch[i] - 65]++;
	}

	for (int i = 0; i < 25; i++) {
		cout << words[i] << ":" << a[i] << endl;
	}

	int i = 1, j = 0;
	for (int k = 0; k < 25; k++) {
		if (a[j] < a[i]) {
			max[0] = words[i];
			j = i;
		}
		i++;
	}

	i = 1, j = 0;
	for (int k = 0; k < 25; k++) {
		if (a[j] < a[i]) {
			if (words[i] != max[0]) {
				max[1] = words[i];
				j = i;
			}
		}
		i++;
	}


	i = 1, j = 0;
	for (int k = 0; k < 25; k++) {
		if (a[j] < a[i]) {
			if (words[i] != max[0] && words[i] != max[1]) {
				max[2] = words[i];
				j = i;
			}
		}
		i++;
	}

	i = 1, j = 0;
	for (int k = 0; k < 25; k++) {
		if (a[j] < a[i]) {
			if (words[i] != max[0] && words[i] != max[1] && words[i] != max[2]) {
				max[3] = words[i];
				j = i;
			}
		}
		i++;
	}

	i = 1, j = 0;
	for (int k = 0; k < 25; k++) {
		if (a[j] < a[i]) {
			if (words[i] != max[0] && words[i] != max[1] && words[i] != max[2] && words[i] != max[3]) {
				max[4] = words[i];
				j = i;
			}
		}
		i++;
	}
	cout << "出现频率从高到低：";
	for (int i = 0; i < 5; i++)
		cout << max[i] << "-" << (int)max[i] - 65 << " ";
	cout << endl;

	int k1 = 0, k2 = 0;
	int H = 1;
	while (gcd(k1, 26) != 1) {
		for (int I = 1; I < 26; I++) {
			for (int J = 0; J < 26; J++) {
				if (((4 * I + J) % 26) == ((int)max[0] - 65) && ((19 * I + J) % 26) == ((int)max[H] - 65)) {
					k1 = I;
					k2 = J;
					H++;
					break;
				}
			}
		}
	}
	cout << "密钥k1和k2为：";
	cout << k1 << " " << k2 << endl;
	cout << "k1的逆元为：" << Ni(k1, 26) << endl;
	jiemi(ch, Ni(k1, 26), k2);
}

int main() {
	string str;
	cin >> str;
	tongji(str);
	return 0;
}
