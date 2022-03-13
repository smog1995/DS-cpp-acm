#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
class RadixSort {
	int *array;
	int max;
	queue<int> radix[10];
	int len;
public:
	RadixSort(int n);
	~RadixSort();
	void Max();
	void Sort();
	void Distribute(int wei);
	void Collect();
};
RadixSort::RadixSort(int n)
{
	len = n;
	array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	Max();
}
RadixSort::~RadixSort()
{
	delete[] array;
}

void RadixSort::Max()
{
	int m = 0;
	for (int i = 0; i < len; i++)
	{
		if (m < array[i]) m = array[i];
	}
	int count = 0;
	while (m)
	{
		m /= 10;
		count++;
	}
	max = count;
}
void RadixSort::Sort()
{
	for (int i = 1; i <= max; i++)
	{
		Distribute(i);
		Collect();
	}
	cout << endl;
}
void RadixSort::Distribute(int t)
{
	int j;
	for (int i = 0; i < len; i++)
	{
		j = array[i] / pow(10, t - 1);
		radix[j % 10].push(array[i]);
	}
}
void RadixSort::Collect()
{
	int num = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << i << ":";
		if (radix[i].empty()) cout << "NULL" << endl;
		else {
			while(!radix[i].empty())
			{
				cout << "->" << radix[i].front();
				array[num++] = radix[i].front();
				radix[i].pop();
			}
			cout << "->^" << endl;
		}
	}
	for (int i = 0; i < len; i++)
	{
		cout << array[i];
		if (i != len - 1)
			cout << " ";
	}
	cout << endl;
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		RadixSort mySort(n);
		mySort.Sort();
		
	}
	return 0;
}