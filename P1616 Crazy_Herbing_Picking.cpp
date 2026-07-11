#include<iostream>
using namespace std; const int N = 1e4 + 5,T = 1e7 + 5;
long long n,t,c,v,f[T];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t >> n;
    for (int i = 1;i <= n;i++){
        cin >> c >> v;
        for (int j = c;j <= t;j++)
            f[j] = max(f[j],f[j - c] + v);
    }
    cout << f[t];
    return 0;
}