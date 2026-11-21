#include<iostream>
using namespace std; using ll = long long; const int N = 5005,P = 1e9 + 7; 
int n; ll s[N],f[N][N];
ll QuickPow(ll a,ll b){
    ll ans = 1;
    while (b){
        if (b & 1)
            ans = ans * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return ans;
}
ll inv(ll x){return QuickPow(x,P - 2);}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> s[i];
        s[i] += s[i - 1];
    }
    f[1][n] = 1;
    for (int len = n;len >= 1;len--)
        for (int i = 1;i + len - 1 <= n;i++){
            int j = i + len - 1;
            for (int k = i;k < j;k++){
                ll &to = (s[k] - s[i - 1] > s[j] - s[k] ? f[i][k] : f[k + 1][j]);
                to = (to + f[i][j] * inv(j - i) % P) % P;
            }
        }
    for (int i = 1;i <= n;i++)
        cout << f[i][i] << '\n';
    return 0;
}
