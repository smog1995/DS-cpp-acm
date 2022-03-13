#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int n;
void Merge(int* a, int l, int r, int m)
{
	int *b = new int[n];
	for (int i = l; i <= r; i++)
		b[i] = a[i];
	int i, j, k;
	for (i = l, j = m + 1, k = l; i <= m && j <= r; k++)
	{
		if (b[i] <= b[j]) a[k] = b[i++];
		else a[k] = b[j++];
	}
	while (i <= m) {
		a[k++] = b[i++];
	}
	while (j <= r)a[k++] = b[j++];
	
}
void MergeSort(int *a, int l, int r,vector<vector<int>>& v1,int i)
{
	vector<int> v;
	if (l < r)
	{
		int m = (l + r) / 2;
		MergeSort(a, l, m,v1,2*i+1);
		MergeSort(a, m + 1, r,v1,2*i+2);
		Merge(a, l, r, m);
		for (int i = l; i <= r; i++)
			v.push_back(a[i]);
		v1[i] = v;

	}
	else {
		v.push_back(a[l]);
		v1[i] = v;
	}
}

int main()
{


		cin >> n;
		int *a = new int[n];
		for (int i = 0; i <n; i++)
			cin >> a[i];
		vector<vector<int>> v(1 * pow(2, n));
		MergeSort(a, 0, n - 1, v,0);
		queue<vector<int>> q;
		stack<vector<int>> s;
		vector<int> v1=v[0];
		q.push(v1);
		int x = 0;
		int count = 0;
		queue<int> q2;
		q2.push(0);
		while (!q.empty())
		{
			v1 = q.front();
			x = q2.front();
			x = x * 2 + 1;
			q.pop();
			q2.pop();
			s.push(v1);
			count++;
			if (x + 1 <= v.size() - 1 && v[x + 1].size() != 0) {
				q.push(v[x + 1]);
				q2.push(x+1);
			}
			if (x <= v.size() - 1 && v[x].size() != 0) {
				q.push(v[x]);
				q2.push(x);
			}
		}
		cout << count << endl;
		while (!s.empty())
		{
			v1 = s.top();
			s.pop();
			for (int i = 0; i < v1.size(); i++)
				cout << v1[i] << " ";
			cout << endl;
		}
}