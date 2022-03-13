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
    	if(p->next==head)//如果因为删除结点使得p->next为头节点，则p也要多移一次。
                p = p->next;
        for(i=0; i<k-1; i++)
        {
            p = p->next;
            if(p->next==head)//在p向后位移的时候如果遇到头结点，则多移一次。
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

