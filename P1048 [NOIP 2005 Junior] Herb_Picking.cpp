#include<iostream>
using namespace std; const int N = 105,T = 1005;
int n,t,c,v,f[T],ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t >> n;
    for (int i = 1;i <= n;i++){
        cin >> c >> v;
        for (int j = t;j >= c;j--)
            f[j] = max(f[j],f[j - c] + v);
    }
    cout << f[t];
    return 0;
}