#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std; const int N = 12;
int n,m,u,v; vector<int> adj[N]; bool vis[N];
void dfs(int st){
    cout << st << ' ';
    for (auto e : adj[st])
        if (!vis[e])
            vis[e] = 1,
            dfs(e);
}
void bfs(int st){
    queue<int> q;
    vis[st] = 1;
    q.push(st);
    while (!q.empty()){
        int f = q.front();
        cout << f << ' ';
        q.pop();
        for (auto e : adj[f])
            if (!vis[e])
                vis[e] = 1,
                q.push(e);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    while (m--){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis[1] = 1;
    dfs(1);
    cout << '\n';
    memset(vis,0,sizeof(vis));
    bfs(1);
    return 0;
}
