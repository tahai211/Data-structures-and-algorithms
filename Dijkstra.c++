//tìm dường đi ngắn nhất của đồ thị co huong hoac vo huong , co trong so la w
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 100001;
int m, n,s,t;
vector<pair<int, int>> adj[maxn];


void input()
{
    cin >> n >> m>>s>>t;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        // Do thi Co huong bo dong duoi
        adj[y].push_back({x, w});
    }
}
const int INF = 1e9; // vo cung
int pre[maxn];//luu duong di ngan nhat

void dijkstra(int s,int t)//s laf dinh bat dau t la dinh can den 
{
    // mang luu khoang cach duong di
    vector<ll> d(n + 1, INF);
    //vector<bool> visited(n+1,false);
    d[s] = 0;
    pre[s] = s;
    // hang doi uu tien
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    //{khoang cach,dinh}
    Q.push({0, s});
    while (!Q.empty())
    {
        // chon ra dinh co khoang cach tu s nho nhat
        pair<int, int> top = Q.top();
        Q.pop();
        int u = top.second;
        int kc = top.first;
        if (kc > d[u])
        {
            continue;
        }
        /*if (visited[u])
        {
            continue;
        }
        visited[u] = true;*/
        
        // Relaxation: cap nhat khoang cach tu s cho toi moi dinh ke voi u
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({d[v], v});
                pre[v] =u;// truoc v la u
            }
        }
    }
    cout<< d[t] << endl;
    vector <int> path;
    while (1)
    {
        path.push_back(t);
        if (t == s)
        {
            break;
        }
        t = pre[t];
    }
    reverse(begin(path),end(path));
    for(int x: path){
        cout<<x<<"  ";
    }
    
    
}
int main()
{
    input();
    dijkstra(s);
}