#include<iostream>
using namespace std; const int N = 105,T = 1e4 + 5;
int n,t,a,f[T];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    f[0] = 1;
    for (int i = 1;i <= n;i++){
        cin >> a;
        for (int j = t;j >= a;j--)
            f[j] += f[j - a];
    }
    cout << f[t];
    return 0;
}