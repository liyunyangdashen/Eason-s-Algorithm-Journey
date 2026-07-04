#include<iostream>
using namespace std; const int N = 25;
int r,c,hx,hy,dhx[] = {0,1,2,2,1,-1,-2,-2,-1},dhy[] = {0,-2,-1,1,2,2,1,-1,-2}; bool g[N][N]; long long f[N];
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
    if (!g[0][0]) f[0] = 1;
    for (int i = 0;i <= r;i++)
        for (int j = 0;j <= c;j++){
            if (!g[i][j]){
                if (j > 0) f[j] += f[j - 1];
            }else
                f[j] = 0;
        }
    cout << f[c];
    return 0;
}