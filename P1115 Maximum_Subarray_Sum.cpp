#include<iostream>
using namespace std; const int N = 2e5 + 5;
int n,a,f[N],maxx = -2e9;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a;
        f[i] = max(a,f[i - 1] + a);
        maxx = max(maxx,f[i]);
    }
    cout << maxx;
    return 0;
}