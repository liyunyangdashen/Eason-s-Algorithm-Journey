#include<iostream>
using namespace std; const int N = 1005,T = N;
int n,t,c,v,w,l; long long sum = 0,f[T];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    for (int i = 1;i <= n;i++){
        cin >> l >> w >> c;
        v = w - l; sum += l;
        for (int j = t;j >= c;j--)
            f[j] = max(f[j],f[j - c] + v);
    }
    cout << (sum + f[t]) * 5;
    return 0;
}