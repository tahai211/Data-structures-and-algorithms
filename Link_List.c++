#include <iostream>

using namespace std;
typedef struct Tnode
{
    int data;
    struct Tnode *pNext;
} Tnode;
typedef struct Tlist
{
    Tnode *pHead;
    Tnode *pTail;
} Tlist;
void khoitao(Tlist &l)
{
    l.pHead = l.pTail = NULL;
}
Tnode *khoitaonode(int x)
{
    Tnode *p = new Tnode;
    if (p == NULL)
    {
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}
Tnode *input()
{
    int x;
    cin >> x;
    return khoitaonode(x);
}
void create_first(Tlist &l, Tnode *n)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = n;
    }
    else
    {
        n->pNext = l.pHead;
        l.pHead = n;
    }
}
void create_last(Tlist &l, Tnode *n)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = n;
    }
    else
    {
        l.pTail->pNext = n;
        l.pTail = n;
    }
}
Tnode *nodeLT;
Tnode *Search(Tlist &l, int x) //ham nayf quan trong de su dung l.pHead == k //l.pTail == k
{

    Tnode *node = l.pHead;
    nodeLT = NULL;
    while (node != NULL && node->data != x)
    {
        nodeLT = node;
        node = node->pNext;
    }
    return node;
}
void create_afterK(Tlist &l, int x, Tnode *q) // k node se chen trc hoac sau no
                                              // q node can chen vao
{
    Tnode *k = Search(l, x);
    if (l.pHead == k)
    {
        create_first(l, q);
    }
    else if (l.pTail == k)
    {
        create_last(l, q);
    }
    else
    {

        if (k->data == x)
        {
            q->pNext = k->pNext;
            k->pNext = q;
            // nodeLT,q,k
        }
        /* if (k->data == x){
             q ->pNext = nodeLT -> pNext;
             nodeLT ->pNext = q;
             //nodeLT,k,q

         }*/
    }
}
void Delete_f(Tlist &l, int x)
{
    Tnode *n = Search(l, x);
    if (n == l.pHead)
    {
        n = l.pHead;
        l.pHead = l.pHead->pNext;
        delete n;
    }
    else if (n == l.pTail)
    {
        delete l.pTail;
        nodeLT->pNext = NULL;
        l.pTail = nodeLT;
    }
    else
    {
        nodeLT->pNext = n->pNext;
        delete n;
    }
}
void show(Tlist &l)
{

    for (Tnode *k = l.pHead; k != NULL; k = k->pNext)
    {
        printf("%d  ", k->data);
    }
}

int main()
{
    Tlist l;
    khoitao(l);
    int n;
    cin >> n;
    Tnode *p;
    for (int i = 0; i < n; i++)
    {
        p = input();
        if (l.pHead == NULL)
        {
            create_first(l, p);
        }
        else
        {
            create_last(l, p);
        }
    }
    show(l);
    int k;
    cin >> k;
    Tnode *q = input();
    create_afterK(l, k, q);
    show(l);
    int f;
    cin >> f;
    Delete_f(l, f);
    show(l);
}