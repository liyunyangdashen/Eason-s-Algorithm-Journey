
#include<iostream>
using namespace std; using ll = long long; const int N = 5005,P = 1e9 + 7;
int n; ll s[N]; int f[N][N],a[N][N],b[N][N],inv[N],l[N],r[N];
ll QuickPow(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b & 1)
            ans = ans * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> s[i];
        s[i] += s[i - 1];
    }
    for (int i = 1;i < n;i++)
        inv[i] = QuickPow(i,P - 2);
    for (int i = 1;i <= n;i++){
        l[i] = 1,r[i] = n;
        for (int j = n;j >= i;j--){
            ll sum = s[j] - s[i - 1];
            while (l[i] < i && s[i - 1] - s[l[i] - 1] > sum)
                l[i]++;
            while (r[i] > j && s[r[i]] - s[j] >= sum)
                r[i]--;
            if (i == 1 && j == n)
                f[i][j] = 1;
            else
                f[i][j] = (1LL * a[i - 1][j] - a[l[i] - 1][j] + b[i][j + 1] - b[i][r[i] + 1] + 2LL * P) % P;
            ll g = (i == j ? 0 : 1LL * f[i][j] * inv[j - i] % P);
            a[i][j] = (a[i - 1][j] + g) % P;
            b[i][j] = (b[i][j + 1] + g) % P;
        }
    }
    for(int i = 1;i <= n;i++)
        cout << f[i][i] << '\n';
    return 0;
}
