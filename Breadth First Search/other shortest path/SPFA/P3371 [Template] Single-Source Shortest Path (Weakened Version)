#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std; const int N = 1e4 + 5,M = 5e5 + 5,INF = (1LL << 31) - 1; using pii = pair<int,int>;
int n,m,s,u,v,w,dis[N]; vector<pii> adj[N]; bool inq[N];
void SPFA(int st){
    fill(dis + 1,dis + n + 1,INF);
    dis[st] = 0;
    queue<int> q;
    inq[st] = true;
    q.push(st);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (auto e : adj[u]){
            int v = e.first,w = e.second;
            if (dis[v] > dis[u] + w && dis[u] < INF){
                dis[v] = dis[u] + w;
                if (!inq[v])
                    inq[v] = true,
                    q.push(v);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    for (int i = 1;i <= m;i++){
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
    }
    SPFA(s);
    for (int i = 1;i <= n;i++)
        cout << dis[i] << ' ';
    return 0;
}
