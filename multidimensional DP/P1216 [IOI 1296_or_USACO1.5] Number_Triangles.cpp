#include<iostream>
using namespace std; const int N = 1005;
int n,a,f[N][N],ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= i;j++){
            cin >> a;
            f[i][j] = max(f[i - 1][j],f[i - 1][j - 1]) + a;
            if (i == n) ans = max(ans,f[i][j]);
        }
    cout << ans;
    return 0;
}
