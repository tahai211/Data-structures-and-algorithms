#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
}Tnode;
typedef struct Stack
{
    Tnode *pTop;
}Tstack;
void KhoitaoStack(Tstack &s){
    s.pTop = NULL;
}
Tnode *KhoitaoNode(int x){
    Tnode *p = new Tnode;
    p->data = x;
    p ->next = NULL;
    return p;
}
bool IsEmpty(Tstack &s){
    if (s.pTop == NULL)
    {
        return true;
    }
    return false;
    
}
bool Push(Tstack &s,Tnode *p){//them vao dau danh sach
    if (p == NULL)
    {
        return false;
    }
    
    if (IsEmpty(s)== true)
    {
        s.pTop = p;
    }else{
        p->next = s.pTop;
        s.pTop = p;
    }
    return true;
}
//lay pt dau ds vaf xoa no di
int Pop(Tstack &s){//x la gia tri can lay
    int x;
    if(IsEmpty(s) == true){
        return 0;
    }else{
        Tnode *p = s.pTop;
        x= p-> data;
        s.pTop = s.pTop ->next;
        delete p;
    }
    return x;

}
//xem gt cua phan tu dau 
int Top(Stack &s){//x la gia tri can lay
    int x;
     if(IsEmpty(s) == true){
        return 0;
    }else{
        x = s.pTop ->data;
    }
    return x;
}
void show(Tstack &s){
    int x;
    while (IsEmpty(s) == false)
    {
        x = Pop(s);
        cout<<x<<" ";

    }
    
}
int main(){
    Tstack s;
    KhoitaoStack(s);
    int t;
    cout<<"nhap vao so phan tu muon them: ";
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int x ;
        cin>>x;
        Tnode *p = KhoitaoNode(x);
        Push(s,p);
    }
    show(s);// xuat het ra tuc laf stack dang rong
}
