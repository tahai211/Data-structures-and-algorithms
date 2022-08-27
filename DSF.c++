#include <iostream>
#include <vector>
using namespace std;
//Graph//Stack
//9 9
//1 2
//1 3
//1 5
//2 4 
//3 6
//3 7
//3 9
//5 8
//8 9
int n ,m;
vector<int> adj[1001];
bool visited[1001];
void input(){
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        //Do thi Co huong bo dong duoi
        adj[y].push_back(x);

    }
    memset(visited,false,sizeof(visited));
}
void dfs(int u){
    cout << u << " ";
    //danh dau la u da duoc tham
    visited[u] = true;
    for(int v : adj[u]){
        //Neu dinh v chua duoc tham
        if(!visited[v]){
            dfs(v);
        }
    }
}
int main(){
    input();
    dfs(1);
}