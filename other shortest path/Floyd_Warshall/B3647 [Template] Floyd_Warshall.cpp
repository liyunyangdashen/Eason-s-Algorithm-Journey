#include<iostream>
#include<cstring>
using namespace std; const int N = 105,INF = 0x3f3f3f3f;
int n,m,u,v,w,floyd[N][N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(floyd,0x3f,sizeof(floyd));
    for (int i = 1;i <= n;i++) floyd[i][i] = 0;
    while (m--){
        cin >> u >> v >> w;
        floyd[u][v] = floyd[v][u] = min(floyd[u][v],w);
    }
    for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                if (floyd[i][k] < INF && floyd[k][j] < INF)
                    floyd[i][j] = min(floyd[i][j],floyd[i][k] + floyd[k][j]);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            cout << floyd[i][j] << " \n"[j == n];
    return 0;
}
