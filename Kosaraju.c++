//Thành Phần Liên Thông Mạnh Của Đồ Thị Có Hướng
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
//Bước 1 : Gọi thuật toán DFS trên đồ thị ban đầu và lưu thứ tự duyệt các đỉnh vào 1 stack
//Bước 2 : Xây dựng đồ thị lật ngược của đồ thị ban đầu : Transpose graph
//Bước 3 : Lần lượt pop các đỉnh trong stack ở bước 1 và gọi thuật toán DFS để liệt kê các thanh phần liên
//thông mạnh : Strongly connected components : SCC
//O(2*(V+E))
 
const int maxn = 100001;
int n, m;
vector<int> adj[maxn], r_adj[maxn];
bool used[maxn];
stack<int> st;
 
//Nhap input
void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        r_adj[y].push_back(x);
    }
}
 
void dfs1(int u){
    used[u] = true;
    for(int v : adj[u]){
        if(!used[v]){
            dfs1(v);
        }
    }
    //da duyet xong dinh u
    st.push(u);
}
 
void dfs2(int u){
    cout << u << " ";
    used[u] = true;
    for(int v : r_adj[u]){
        if(!used[v]){
            dfs2(v);
        }
    }
}
 
void SCC(){
    memset(used, false, sizeof(used));
    //B1 : Goi thuat toan dfs tren do thi ban dau
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            dfs1(i);
        }
    }
    memset(used, false, sizeof(used));
    while(!st.empty()){
        int u = st.top(); st.pop();
        if(!used[u]){
            dfs2(u);
            cout << endl;
        }
    }
 
}
 
int main(){
    
    inp();
    SCC();
}