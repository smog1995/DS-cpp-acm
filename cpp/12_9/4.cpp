#include <iostream>
#include <math.h>
using namespace std;
class Four
{
	int d, w;
	int **n;
public:
	Four(int x1);
	//Four(Four&);
	~Four() { delete[] n; };
	Four& operator+(Four&);
	int BtoF(int **a, int w, int last);
	void getFD() { cout << d << endl; };
	void createBinary(int w);
};
/*Four::Four(Four& f)
{
	d = f.d;
	w = f.w;
	n = new int*[w];
	for (int i = 0; i < n; i++)
		n[i] = new int[2];
	for (int i = 0; i < w; i++)
	{
		n[i][0] = f.n[i][0];
		n[i][1] = f.n[i][1];
	}
}
*/
Four& Four::operator+(Four& f)
{
	int W = 0;
	if (w > f.w) W = w;
	else W = f.w;
	f.createBinary(W);
	createBinary(W);
	int D=0;//即将返回的四进制数
	int last = 0;
	for (int i = W - 1; i >= 0; i--)//从右到左开始
	{
		if (i != 0)
		{
			n[i][0] += (n[i][1] + f.n[i][1]) / 2;
			n[i][1] =(n[i][1] +f.n[i][1])%2;
			n[i-1][1]+= (n[i][0] + f.n[i][0]) / 2;
			n[i][0] = (n[i][0] + f.n[i][0]) % 2;
		}
		else if (i == 0)
		{
			n[i][0]+= (n[i][1] + f.n[i][1]) / 2;
			n[i][1] = (n[i][1] + f.n[i][1]) % 2;
			last+= (n[i][0] + f.n[i][0]) /2;
			n[i][0]= (n[i][0] + f.n[i][0]) % 2;
		}//多添加一位
	}
	D = BtoF(n, W, last);
	d = D;
	return *this;
}
int Four::BtoF(int **a, int w, int last)
{
	int d1 = 0;
	d1 += last ;
	for (int i = 0; i < w ; i++)
	{
		d1 = d1* 10+ (a[i][0] * 2 + a[i][1]);
	}
	return d1;
}
void Four::createBinary(int w)
{
	this->w = w;
	//delete[] n;//如果一开始n不为空指针
	n = new int*[w];//w代表十进制的位数
	int d1 = d;
	for (int i = 0; i < w; i++)
		n[i] = new int[2];
	for (int i =0; i <w; i++) 
	{
		int a = pow(10, w-1-i);
		if (d1 / a == 0)
		{
			n[i][0] = 0; n[i][1] = 0;
		}
		else if (d1 / a == 1)
		{
			n[i][0] = 0; n[i][1] = 1;
		}
		else if (d1 /a == 2)
		{
			n[i][0] = 1; n[i][1] = 0;
		}
		else if (d1 / a == 3)
		{
			n[i][0] = 1; n[i][1] = 1;
		}
		
		d1%= a;
	}
}
Four::Four(int d1):d(d1)
{
	w = 0;
	while (d1 != 0)
	{
		d1 /= 10;
		w++;
	}
}
int main()
{
	int t, d;
	cin >> t >> d;
	Four f(d);
	t--;
	while (t--)
	{
		cin >> d;
		Four f1(d);
		f = f + f1;
	}
#include <iostream>
#include <math.h>
	using namespace std;
	class Four
	{
		int d, w;
		int **n;
	public:
		Four(int x1);
		//Four(Four&);
		~Four() { delete[] n; };
		Four& operator+(Four&);
		int BtoF(int **a, int w, int last);
		void getFD() { cout << d << endl; };
		void createBinary(int w);
	};
	/*Four::Four(Four& f)
	{
		d = f.d;
		w = f.w;
		n = new int*[w];
		for (int i = 0; i < n; i++)
			n[i] = new int[2];
		for (int i = 0; i < w; i++)
		{
			n[i][0] = f.n[i][0];
			n[i][1] = f.n[i][1];
		}
	}
	*/
	Four& Four::operator+(Four& f)
	{
		int W = 0;
		if (w > f.w) W = w;
		else W = f.w;
		f.createBinary(W);
		createBinary(W);
		int D = 0;//即将返回的四进制数
		int last = 0;
		for (int i = W - 1; i >= 0; i--)//从右到左开始
		{
			if (i != 0)
			{
				n[i][0] += (n[i][1] + f.n[i][1]) / 2;
				n[i][1] = (n[i][1] + f.n[i][1]) % 2;
				n[i - 1][1] += (n[i][0] + f.n[i][0]) / 2;
				n[i][0] = (n[i][0] + f.n[i][0]) % 2;
			}
			else if (i == 0)
			{
				n[i][0] += (n[i][1] + f.n[i][1]) / 2;
				n[i][1] = (n[i][1] + f.n[i][1]) % 2;
				last += (n[i][0] + f.n[i][0]) / 2;
				n[i][0] = (n[i][0] + f.n[i][0]) % 2;
			}//多添加一位
		}
		D = BtoF(n, W, last);
		d = D;
		return *this;
	}
	int Four::BtoF(int **a, int w, int last)
	{
		int d1 = 0;
		d1 += last;
		for (int i = 0; i < w; i++)
		{
			d1 = d1 * 10 + (a[i][0] * 2 + a[i][1]);
		}
		return d1;
	}
	void Four::createBinary(int w)
	{
		this->w = w;
		//delete[] n;//如果一开始n不为空指针
		n = new int*[w];//w代表十进制的位数
		int d1 = d;
		for (int i = 0; i < w; i++)
			n[i] = new int[2];
		for (int i = 0; i < w; i++)
		{
			int a = pow(10, w - 1 - i);
			if (d1 / a == 0)
			{
				n[i][0] = 0; n[i][1] = 0;
			}
			else if (d1 / a == 1)
			{
				n[i][0] = 0; n[i][1] = 1;
			}
			else if (d1 / a == 2)
			{
				n[i][0] = 1; n[i][1] = 0;
			}
			else if (d1 / a == 3)
			{
				n[i][0] = 1; n[i][1] = 1;
			}

			d1 %= a;
		}
	}
	Four::Four(int d1) :d(d1)
	{
		w = 0;
		while (d1 != 0)
		{
			d1 /= 10;
			w++;
		}
	}
	int main()
	{
		int t, d;
		cin >> t >> d;
		Four f(d);
		t--;
		while (t--)
		{
			cin >> d;
			Four f1(d);
			f = f + f1;
			f.getFD();
		}
	}

}
