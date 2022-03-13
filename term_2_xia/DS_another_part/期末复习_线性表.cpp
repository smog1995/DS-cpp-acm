#include <iostream>
using namespace std;
class SeqList
{
	private:
		int *list;
		int maxsize;
		int size;
	public:
	SeqList(int n) :size(n), maxsize(1000) {
        list = new int[1000];
        for(int i=0;i<size;i++)
        scanf("%d",&list[i]);
    }
 	~SeqList(){
		delete[] list;
	}
	int list_size(){return size;
	}
	int list_insert(int i,int item)
	{
		if(i<1||i>size+1) {
			printf("error\n");
			return -1;
		}
		for(int j=size-1;j>=i-1;j--)
			list[j+1]=list[j];
			list[i-1]=item;
			size++;
			list_display();
		return 1;
	}
	int multiinsert(int i, int n, int item[])
	{
		for(int j=size-1;j>=i-1;j--)
			list[j+n]=list[j];
		for(int j=i-1;j<i-1+n;j++)
		list[j]=item[j-i+1];
		size+=n;
		list_display();
	}
	int multidel(int i, int n)
	{
		for(int j=i-1;j<=size-n-1;j++)
		list[j]=list[j+n];
		size-=n;
		list_display();
	}
	int list_del(int i)
	{
		if(i<1||i>size) 
		{
			printf("error\n");
			return -1;
		}
		for(int j=i-1;j<size-1;j++)
			list[j]=list[j+1];
			size--;
		return 1;
	}	
	int list_get(int i)
    {
        if (i<1 || i>size) { cout << "error" << endl; return -1; }
        cout << list[i - 1] << endl;
        return 1;
    }
	void list_display()
    {
        cout << size << " ";
 
        for (int i = 0; i < size; i++)
            cout << list[i] << " ";
        cout << endl;
    }
		
}; 
int main()
{
    int n;
    scanf("%d",&n);
    SeqList L(n);
    L.list_display();
    int pos,num;
    scanf("%d %d",&pos,&num);
	int *item=new int[num];
	for(int i=0;i<num;i++)
	scanf("%d",&item[i]);
	L.multiinsert(pos,num,item);
	scanf("%d %d",&pos,&num);
	L.multidel(pos,num);

 
 
}

