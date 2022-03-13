#include <iostream>
#include <stdlib.h>
#include<vector>
#include <ctime>
using namespace std;
typedef long long ll;
/*
void exgcd(ll a, ll b, ll& d, ll& x, ll& y) {
	if (!b) { d = a; x = 1; y = 0; }
	else { exgcd(b, a%b, d, y, x); y -= x * (a / b); }
}
ll inv(ll a, ll p)
{
	ll d, x, y;
	exgcd(a, p, d, x, y);
	return d == 1 ? (x + p) % p : -1;
}
*/
struct gcdstruct {
	int d;
	int x;
	int y;
};
gcdstruct EXTENDED_EUCLID(int a, int b)
{
	gcdstruct aa, bb;
	if (b == 0) {
		aa.d = a;
		aa.x = 1;
		aa.y = 0;
		return aa;
	}
	else {
		bb = EXTENDED_EUCLID(b, a%b);
		aa.d = bb.d;
		aa.x = bb.y;
		aa.y = bb.x - bb.y * (a / b);
	}
	return aa;
}


ll inverse(ll a, ll m)
{
	ll x;
	gcdstruct aa;
	aa = EXTENDED_EUCLID(a, m);
	
	return (aa.x+m)%m;

}
ll mod_mul(ll a, ll b, ll mod)
{
	ll res = 0;
	while (b)
	{
		if (b & 1)
			res = (res + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return res;
}

ll mod_pow(ll a, ll n, ll mod)
{
	ll res = 1;
	while (n)
	{
		if (n & 1)
			res = mod_mul(res, a, mod);
		a = mod_mul(a, a, mod);
		n >>= 1;
	}
	return res;
}
int ToolRandInt(int min, int max)
{
	srand((unsigned)time(NULL));
	int r = rand() % (max - min + 1) + min;
	return r;
}
int main()
{
	ll p;
	int s = ToolRandInt(1,10000);
	int w, t;
	cin >> p >> w >> t;
	int *x, *a;
	ll **result;
	x = new int[w];
	a = new int[t];
	result = new ll*[w];
	for (int i = 0; i < w ; i++)
	{
		result[i] = new ll[2];
	}
	for (int i = 0; i <t; i++)//生成随机数a
	{
		a[i] = ToolRandInt(w + 1, 50);
		for (int j = 0; j < i; j++)
		{
			if (a[i] == a[j])
			{
				a[i] = ToolRandInt(w + 1, 50);
				j = 0;
			}
		}
	}
	for (int i = 0; i < w ; i++)
	x[i] = i;
	for (int i = 0; i < w ; i++)
	{
		ll y = s;//h(xi)多项式的值，带有a0(a0即为密钥）
		for (int i1 = 0; i1 < t; i1++)
		{
			y += a[i1] * mod_pow(x[i], i1 + 1, p) ;
			y %= p;
		}
		result[i][0] = x[i];
		result[i][1] = y;//共有w-1组，即有w-1个碎片 
	}
	ll s1 = 0;//恢复后所得的密钥s 
	ll *fz=new ll[t], *fm = new ll[t];
	for (int i = 0; i < t; i++)
	{
	fz[i] = result[i][1];
	fm[i] = 1;
		for (int i1 = 0; i1 < t; i1++)
		{
			if (i != i1)
			{
				fz[i] *= (-x[i1]);
				fm[i]*= (x[i] - x[i1]);
			}
		}
	//	s1 += lx;
		//if (s1 < 0) s1 = (s1 + p) % p;
	}
	ll FZ = 0, FM = 1;
	for (int i = 0; i <t; i++) {
		FZ = FZ * fm[i] + FM * fz[i];
		FM = FM * fm[i];
	}
	
	if (FZ < 0)FZ = (FZ + p) % p;
	s1 = FZ * inverse(FM, p) % p;
	cout << s1-s << endl;

}