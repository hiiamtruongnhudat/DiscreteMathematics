#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    struct node* pNext;
} Node;
typedef struct listt{
    Node *pHead;
    Node *pTail;
}ListNode;
void createList(ListNode &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
Node *createNode(int x)
{
    Node *p = new Node;
    p->data = x;
    p->pNext = NULL;
    return p;
}
void addNodeTop(ListNode &l, Node *p)
{
    if (l.pHead==NULL)
        l.pHead = l.pTail = p;
    else
        {
            p->pNext = l.pHead;
            l.pHead = p;

        }
}
void addNodeBot(ListNode &l, Node *p)
{
    if (l.pHead==NULL)
        l.pHead = l.pTail = p;
    else
        {
            l.pTail->pNext = p;
            l.pTail = p;

        }
}
void printResult(ListNode l)
{
    for (Node *k = l.pHead; k != NULL; k = k->pNext)
    {
        cout << k->data << " ";
    }
}
int main()
{
    ListNode l;
    createList(l);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        {   
            int x; cin >> x;
            Node *p = createNode(x);
            addNodeBot(l,p);
        }
    printResult(l);
    return 0;
}