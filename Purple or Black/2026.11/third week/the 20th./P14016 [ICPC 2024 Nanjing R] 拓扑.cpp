#include<iostream>
#include<vector>
using namespace std; using ll = long long; const int N = 5005,P = 998244353; 
int n,fa[N]; ll siz[N],mulsiz[N],f[N][N],fac[N],invfac[N]; vector<int> adj[N];
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
ll inv(int x){return QuickPow(x,P - 2);}
ll Combination(int n,int k){if (n < 0 || k < 0 || n < k) return 0; return 1LL * fac[n] * invfac[k] % P * invfac[n - k] % P;}
void dfs(int st,int p){
    siz[st] = 1;
    mulsiz[st] = 1;
    for (auto e : adj[st])
        if (e != p){
            dfs(e,st);
            siz[st] = (siz[st] + siz[e]) % P;
            mulsiz[st] = mulsiz[st] * mulsiz[e] % P;
        }
    mulsiz[st] = mulsiz[st] * siz[st] % P;
}
void dfs_d(int st,int p){
    for (auto e : adj[st])
        if (e != p){
            ll m = siz[st] - siz[e] - 1,sum = 0;
            ll k = 1LL * fac[m] * siz[st] % P * mulsiz[e] % P * inv(mulsiz[st]) % P;
            for(int j = 1;j <= n - siz[e] + 1;j++){
                int i = j - 1;
                if (i >= 1)
                    sum = (sum + 1LL * f[st][i] * Combination(n - siz[e] - i,m) % P) % P;
                f[e][j] = 1LL * k * sum % P;
            }
            dfs_d(e,st);
        }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fac[0] = 1;
    for (int i = 1;i <= n;i++)
        fac[i] = fac[i - 1] * i % P;
    invfac[n] = inv(fac[n]);
    for (int i = n - 1;i >= 0;i--)
        invfac[i] = invfac[i + 1] * (i + 1) % P;
    for (int i = 2;i <= n;i++){
        cin >> fa[i];
        adj[fa[i]].push_back(i);
        adj[i].push_back(fa[i]);
    }
    dfs(1,0);
    f[1][1] = 1;
    dfs_d(1,0);
    for (int i = 1;i <= n;i++)
        cout << f[i][i] * Combination(n - i,siz[i] - 1) % P * fac[siz[i]] % P * inv(mulsiz[i]) % P << ' ';
    return 0;
}
