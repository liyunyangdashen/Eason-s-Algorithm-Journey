#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
#include<queue>
using namespace std; using pii = pair<int,int>; 
const int N = 1e3 + 5,M = 1e5 + 5,INF = 0x3f3f3f3f; 
int n,m,u,v,w,rtdis[N],opdis[N],ans = 0; bool vis[N]; vector<pii> rtadj[N],opadj[N];
void Dijkstra(int st,vector<pii> adj[],int dis[]){
    memset(vis,0,sizeof(vis));
    dis[st] = 0;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push(make_pair(0,st));
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1; 
        for (int i = 0;i < adj[u].size();i++){
            int v = adj[u][i].first,w = adj[u][i].second;
            if (dis[u] + w < dis[v] && dis[u] < INF){
                dis[v] = dis[u] + w;
                pq.push(make_pair(dis[v],v));
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    while (m--){
        cin >> u >> v >> w;
        rtadj[u].push_back(make_pair(v,w));
        opadj[v].push_back(make_pair(u,w));
    }
    memset(rtdis,0x3f,sizeof(rtdis));
    Dijkstra(1,rtadj,rtdis);
    memset(opdis,0x3f,sizeof(opdis));
    Dijkstra(1,opadj,opdis);
    for (int i = 1;i <= n;i++)
        ans += rtdis[i] + opdis[i];
    cout << ans;
    return 0;
}
