#include <iostream>
using namespace std;
template<class T>
T max(T* t, int n)
{
	T m=t[0];
	for (int i = 0; i < n; i++)
		if (m < t[i])m = t[i];
	return m;
}

template <class T>
class Cryption {
	T ptxt[100];	//����
	T ctxt[100];	//����
	T key;	//��Կ
	int len;	//����
public:
	Cryption(T tk, T tt[], int t):key(tk),len(t)
	{
		for (int i = 0; i < len; i++)
			ptxt[i] = tt[i];
	} //�������ζ�Ӧ��Կ�����ġ�����
	void Encrypt() //����
	{
		T max1 = max(ptxt, len);
		for (int i = 0; i < len; i++)
			ctxt[i] = max1 - ptxt[i];
		for (int i = 0; i < len; i++)
			ctxt[i] += key;
	}
	void Print() //��ӡ���������
	{
		int i;
		for (i = 0; i < len - 1; i++)
			cout << ctxt[i] << " ";
		cout << ctxt[i] << endl;
	}
};
//template<class T>
//Cryption::Cryption(T tk, T tt[], int t1) 
//template<class T>
//void Cryption::Encrypt()

//֧���������͵�������
int main()
{
	int i;
	int length; //����
	int ik, itxt[100];
	double dk, dtxt[100];
	char ck, ctxt[100];
	//��������
	cin >> ik >> length;
	for (i = 0; i < length; i++)
		cin >> itxt[i];
	Cryption<int> ic(ik, itxt, length);
	ic.Encrypt();
	ic.Print();
	//����������
	cin >> dk >> length;
	for (i = 0; i < length; i++)
		cin >> dtxt[i];
	Cryption<double> dc(dk, dtxt, length);
	dc.Encrypt();
	dc.Print();
	//�ַ�����
	cin >> ck >> length;
	for (i = 0; i < length; i++)
		cin >> ctxt[i];
	Cryption<char> cc(ck, ctxt, length);
	cc.Encrypt();
	cc.Print();

	return 0;
}