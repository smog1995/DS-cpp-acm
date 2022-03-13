#include <iostream>
#include <strstream>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
	//第一，练习使用字串流以及getcahr（）
	char str[30] = "ILOVE U";
	istrstream is(str,7);
	//后面的size是指该流所要的数组大小，而且istr流，
	//字符串的特性，遇到空格就为结束符，所以U不会输出
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


	//getchar()这里会等待用户输入字符，
//然后存到键盘缓冲区，然后getchar函数从键盘缓冲区拿出一个字符作为返回值
	//此后，若还有getchar（）也不会等待用户输入了，因为键盘缓冲区还有东西，
	//等到键盘缓冲区完全输完后若还有getchar()函数，才会继续要求用户输入
	//也就是说，只要键盘缓冲区没东西，getchar()就会要求用户输入字符




	cout << "-------------------------------" << endl;
	
	
	
	//第二，练习使用标识符

	//--------------------------------------
	//setfill，成员函数为flags(c)，c为填充字符；
	//setw(10)为设置宽度，成员函数为width(n)
	//oct为八进制，成员函数为flags(8),相应的16进制为16，10为10
	cout << setfill(' ') << setw(10) << oct << 20;
	int prePrecision = cout.precision(4);//该函数返回值为原来的有效位数.
	cout << "-------------------------------" << endl;

	
	//第三练习文件流
	//--------------------------------------
	
	ofstream outfile;
	outfile.open("D:\\code\\myname.txt", ios::out);

	if (outfile.fail())//=-1表示失败
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
