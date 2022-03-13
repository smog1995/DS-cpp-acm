#include <iostream>
using namespace std;

class Node {
public:
 int data;
 Node* lchild, * rchild;
};

class Tree {
 Node* root;
 void MidOrder(Node* p) {
  while (p) {
   MidOrder(p->lchild);
   cout << p->data << " ";
   MidOrder(p->rchild);
  }
 }
public:
 Tree(int n) {
  root = NULL;
  int key;
  while (n--) {
   cin >> key;
   insert(root,key);
  }
 }
 void insert(Node *t,int key) {
  if (!t) {
   t = new Node;
   t->data = key;
   t->lchild = NULL;
   t->rchild = NULL;
  }
  else if (key < t->data) {
   insert(t->lchild, key);
  }
  else
   insert(t->rchild, key);
 }
 void MidOrder() {//中序遍历外部接口
  MidOrder(root);
 }
 void insert(int key) {//外部接口
  insert(root, key);
 }
};

int main() {
 int t,*a,n;
 cin >> t;
 while (t--) {
  cin >> n;
  Tree T(n);
  T.MidOrder();
  cout << endl;
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
   int key;
   cin >> key;
   T.insert(key);
   T.MidOrder();
   cout << endl;
  }
 }
}
