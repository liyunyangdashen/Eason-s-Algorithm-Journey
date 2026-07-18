#include<iostream>
using namespace std; const int N = 1005,W = 1e4 + 5,P = 1e9 + 7;
int n,w,a[N],f[W];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;
    f[0] = 1;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    for (int i = 1;i <= w;i++)
        for (int j = 1;j <= n;j++)
            if (a[j] <= i)
                f[i] = (f[i] + f[i - a[j]]) % P;
    cout << f[w];
    return 0;
}