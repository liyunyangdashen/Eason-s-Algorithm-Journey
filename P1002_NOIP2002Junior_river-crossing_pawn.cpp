#include<iostream>
using namespace std; const int N = 25;
int r,c,hx,hy,dx[] = {1,0},dy[] = {0,1},dhx[] = {0,1,2,2,1,-1,-2,-2,-1},dhy[] = {0,-2,-1,1,2,2,1,-1,-2},ans; bool g[N][N],vis[N][N];
void dfs(int stx,int sty){
    if (stx == r && sty == c){
        ans++;
        return ;
    }
    for (int i = 0;i < 2;i++){
        int nx = stx + dx[i],ny = sty + dy[i];
        if ((nx >= 0 && nx <= r && ny >= 0 && ny <= c) && !(g[nx][ny] || vis[nx][ny]))
            vis[nx][ny] = 1,
            dfs(nx,ny),
            vis[nx][ny] = 0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c >> hx >> hy;
    for (int i = 0;i < 9;i++){
        int nhx = hx + dhx[i],nhy = hy + dhy[i];
        if (nhx >= 0 && nhx <= r && nhy >= 0 && nhy <= c)
            g[nhx][nhy] = 1;
    }
    dfs(0,0);
    cout << ans;
    return 0;
}