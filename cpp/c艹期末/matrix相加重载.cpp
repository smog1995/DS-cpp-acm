#include <iostream>
using namespace std;
class Matrix
{
	int r,c;
	int **data;
	public:
		Matrix(int r1,int c1):r(r1),c(c1)
		{
			data=new int*[r];  //先创建m行
			for(int i=0;i<r;i++)
		  { data[i]=new int[c]; }  //再创建n列
		
			for (int i=0; i<r; i++)
		 	 for (int j=0; j<c; j++)
		    cin>>data[i][j];
		}
		Matrix& operator+(const Matrix& m1);
		~Matrix();
		void print()
		{
		    for (int i = 0; i < r; i++)
		    {
		        for (int i1 = 0; i1 < c; i1++)
		        {
		            cout << data[i][i1] << " ";
		        }
		        cout << endl;
		         
		    }
		}	
 };
 Matrix& Matrix::operator+(const Matrix& m1)
 {
 	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
		 	data[i][j]+=m1.data[i][j];
		return *this;
 }
 Matrix::~Matrix()
 {
 	for(int i=0;i<r;i++)
 	delete[] data[i];
 	delete[] data;
 }
 int main()
 {
 	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        Matrix m1(m, n);
        Matrix m2(m, n);
        (m1 + m2).print();
    }
 }
