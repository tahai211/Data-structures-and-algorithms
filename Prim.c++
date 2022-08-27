//cây khung cực tiểu/nhỏ nhất 
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
struct canh
{
    int x, y, w;
};

int m, n;
vector<pair<int, int>> adj[maxn];
bool used[maxn];
// int parent[maxn],d[maxn];
void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        // Do thi Co huong bo dong duoi
        adj[y].push_back({x, w});
    }
    memset(used, false, sizeof(used));
    /*for (int  i = 1; i <= n; i++)
    {
        d[i] = INT_MAX;
    }*/
}/*
// dung hang doi uu tien
void prim(int u)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    vector<canh> MST;
    int res = 0;
    Q.push({0, u});
    while (!Q.empty())
    {
        pair<int, int> top = Q.top();
        Q.pop();
        int dinh = top.second;
        int trongso = top.first;
        if (used[dinh])
        {
            continue;
        }
        res += trongso;
        used[dinh] = true;
        if (u != dinh)
        {
            MST.push_back({dinh, parent[dinh], trongso});
        }
        // duyet tat ca cac dinh ke
        for (auto it : adj[dinh])
        {
            int y = it.first, w = it.second;
            if (!used[y] && w < d[y])
            {
                Q.push({w, y});
                d[y] = w;
                parent[y] = dinh;
            }
        }
    }
    cout << res << endl;
    for (auto it : MST)
    {
        cout << it.x << "  " << it.y << "  " << it.w << endl;
    }
}*/
void prim(int u)
{
    vector<canh> MST; // cay khung
    int d = 0;        // chieu dai cay khung
    used[u] = true;   // dua dinh u vao tap V(MST)
    while (MST.size() < n - 1)
    {
        // e = (x,y) : canh ngan nhat co x thuoc v va y thuoc v(MST)
        int min_w = INT_MAX;
        int X, Y;
        for (int i = 1; i <= n; i++)
        {
            // neu dinh i thuoc tap V(MST)
            if (used[i])
            {
                // duyet danh sach ke cua dinh i
                for (pair<int, int> it : adj[i])
                {
                    int j = it.first, trongso = it.second;
                    if (!used[j] && trongso < min_w)
                    {
                        min_w = trongso;
                        X = j;
                        Y = i;
                    }
                }
            }
        }
        MST.push_back({X, Y, min_w});
        d += min_w;
        used[X] = true; // cho dinh X vao V(MST),loai X khoi tap V
    }
    cout << d << endl;
    for (canh e : MST)
    {
        cout << e.x << "  " << e.y << "  " << e.w << endl;
    }
}