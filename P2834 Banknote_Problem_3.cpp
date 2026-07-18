#include<iostream>
using namespace std; const int N = 1005,W = 1e4 + 5,P = 1e9 + 7;
int n,w,a,f[W];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;
    f[0] = 1;
    for (int i = 1;i <= n;i++){
        cin >> a;
        for (int j = a;j <= w;j++)
            f[j] = (f[j] + f[j - a]) % P;
    }
    cout << f[w];
    return 0;
}