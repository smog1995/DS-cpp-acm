#include <iostream>
#include <strstream>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
	//��һ����ϰʹ���ִ����Լ�getcahr����
	char str[30] = "ILOVE U";
	istrstream is(str,7);
	//�����size��ָ������Ҫ�������С������istr����
	//�ַ��������ԣ������ո��Ϊ������������U�������
	char c[20];
	is >> c;
	cout << c << endl;
	cout << getchar() << endl;
	cout << getchar() << endl;
	int i = 0;
	//cout << is << endl;
	/*while (getchar() != '\n')
	{
		cout << i++ << endl;
	}*/


	//getchar()�����ȴ��û������ַ���
//Ȼ��浽���̻�������Ȼ��getchar�����Ӽ��̻������ó�һ���ַ���Ϊ����ֵ
	//�˺�������getchar����Ҳ����ȴ��û������ˣ���Ϊ���̻��������ж�����
	//�ȵ����̻�������ȫ�����������getchar()�������Ż����Ҫ���û�����
	//Ҳ����˵��ֻҪ���̻�����û������getchar()�ͻ�Ҫ���û������ַ�




	cout << "-------------------------------" << endl;
	
	
	
	//�ڶ�����ϰʹ�ñ�ʶ��

	//--------------------------------------
	//setfill����Ա����Ϊflags(c)��cΪ����ַ���
	//setw(10)Ϊ���ÿ�ȣ���Ա����Ϊwidth(n)
	//octΪ�˽��ƣ���Ա����Ϊflags(8),��Ӧ��16����Ϊ16��10Ϊ10
	cout << setfill(' ') << setw(10) << oct << 20;
	int prePrecision = cout.precision(4);//�ú�������ֵΪԭ������Чλ��.
	cout << "-------------------------------" << endl;

	
	//������ϰ�ļ���
	//--------------------------------------
	
	ofstream outfile;
	outfile.open("D:\\code\\myname.txt", ios::out);

	if (outfile.fail())//=-1��ʾʧ��
	{
		cerr << "error" << endl;
	}
	outfile << "wdnmd" << endl;
	ifstream infile;
	infile.open("D:\\code\\myname");
	char s[20];
	infile >> s;
	cout << s << endl;
	infile.close();
	outfile.close();
	
}
