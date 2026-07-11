#include<iostream>
using namespace std; const int N = 35,T = 2e4 + 5;
int n,t,c,f[T];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t >> n;
    for (int i = 1;i <= n;i++){
        cin >> c;
        for (int j = t;j >= c;j--)
            f[j] = max(f[j],f[j - c] + c);
    }
    cout << t - f[t];
    return 0;
}