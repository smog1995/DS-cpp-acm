#include <iostream>
using namespace std;

class ListNode
{
    int data;
    ListNode *next;
    friend class LinkList;
};

class LinkList
{
    int len;
    ListNode *head;
public:
    int n, k, s;
    LinkList();
    ~LinkList();
    void CreateList();
    void Test();
};

LinkList::LinkList()
{
    head = new ListNode;
}

LinkList::~LinkList()
{
    delete head;
}

void LinkList::CreateList()
{
    len = n;
    ListNode *p = head;
    ListNode *q;
    for(int i=1; i<=n; i++)
    {
        q = new ListNode;
        q->data = i;
        p->next = q;
        p = p->next;
    }
    p->next = head;
}

void LinkList::Test()
{
    int i;
    ListNode *p = head;
    for(i=0; i<s-1; i++)
        p = p->next;
    while(len)
    {
    	if(p->next==head)//�����Ϊɾ�����ʹ��p->nextΪͷ�ڵ㣬��pҲҪ����һ�Ρ�
                p = p->next;
        for(i=0; i<k-1; i++)
        {
            p = p->next;
            if(p->next==head)//��p���λ�Ƶ�ʱ���������ͷ��㣬�����һ�Ρ�
                p = p->next;
        }
        ListNode *q = p->next;
        cout<<q->data<<' ';
        p->next = q->next;
        delete q;
        len--;
    }
    cout<<endl;
}

int main(void)
{
    int N, K, S;
    while(scanf("%d%d%d", &N, &K, &S)!=EOF)
    {
        LinkList myList;
        myList.n = N;
        myList.k = K;
        myList.s = S;
        myList.CreateList();
        myList.Test();
    }
    return 0;
}

