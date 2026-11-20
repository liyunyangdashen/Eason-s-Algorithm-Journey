#include<iostream>
using namespace std; using ll = long long; const int N = 2005;
int n,p; ll p2[N],fa[N][N],fb[N][N],fc[N][N],ans[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p;
    p2[0] = 1 % p;
    for (int i = 1;i <= n;i++)
        p2[i] = p2[i - 1] * 2 % p;
    fa[1][0] = fb[1][1] = fc[1][1] = 1;
    for (int i = 1;i < n;i++)
        for (int j = 1;j <= i;j++){
            ll w = (p2[i - j + 1] - 1 + p) % p;
            ll t = fa[i][j - 1] * w % p;
            ans[i + 1] = (ans[i + 1] + t) % p;
            fa[i + 1][j - 1] = (fa[i + 1][j - 1] + t) % p,
            fa[i + 1][j] = (fa[i + 1][j] - t + p) % p;
            fb[i + 1][j + 1] = (fb[i + 1][j + 1] + fb[i][j]) % p,
            fb[i + 1][j] = (fb[i + 1][j] + fb[i][j] * (p2[i] - 1 + p) % p) % p;
            ll w2 = p2[i - j];
            fc[i + 1][j + 1] = (fc[i + 1][j + 1] + fc[i][j] * w2) % p,
            fc[i + 1][j] = (fc[i + 1][j] + fc[i][j] * w2) % p;
        }
    for (int k = 2;k <= n;k++){
        ll sum = 0;
        for (int t = k;t <= n;t++)
            sum = (sum + fb[t - 1][k - 1] * fc[n - 1][t - 1] % p * p2[n-t] % p) % p;
        ans[k] = ans[k] * sum % p;
    }
    ans[0] = ans[2];
    ans[1] = 0;
    for (int k = 0;k <= n;k++)
        cout << ans[k] << ' ';
    return 0;
}
