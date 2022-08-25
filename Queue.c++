#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
}Tnode;
typedef struct Queue
{
    Tnode *pHead;
    Tnode *pTail;
}Tqueue;
void KhoitaoQueue(Tqueue &q){
    q.pHead = q.pTail = NULL;
}
Tnode *KhoitaoNode(int x){
    Tnode *p = new Tnode;
    p->data = x;
    p ->next = NULL;
    return p;
}
bool IsEmpty(Tqueue &q){
    if (q.pHead == NULL)
    {
        return true;
    }
    return false;
    
}
bool Push(Tqueue &q,Tnode *p){//them vao dau danh sach
    if (p == NULL)
    {
        return false;
    }
    
    if (IsEmpty(q)== true)
    {
        q.pHead = q.pTail = p;
    }else{
        q.pTail -> next = p ;
        q.pTail = p;
    }
    return true;
}
//lay pt dau ds vaf xoa no di
int Pop(Tqueue &q){//x la gia tri can lay
    int x;
    if(IsEmpty(q) == true){
        return 0;
    }else{
        Tnode *p = q.pHead;
        x= p-> data;
        q.pHead = q.pHead ->next;
        delete p;
    }
    return x;

}
//xem gt cua phan tu dau 
int Top(Tqueue &q){//x la gia tri can lay
    int x;
     if(IsEmpty(q) == true){
        return 0;
    }else{
        x = q.pHead ->data;
    }
    return x;
}
void show(Tqueue &q){
    int x;
    while (IsEmpty(q) == false)
    {
        x = Pop(q);
        cout<<x<<" ";

    }
    
}
int main(){
    Tqueue q;
    KhoitaoQueue(q);
    int t;
    cout<<"nhap vao so phan tu muon them: ";
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int x ;
        cin>>x;
        Tnode *p = KhoitaoNode(x);
        Push(q,p);
    }
    show(q);// xuat het ra tuc la queue dang rong
}
