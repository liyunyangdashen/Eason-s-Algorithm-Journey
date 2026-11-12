#include<iostream>
#include<cstring>
using namespace std; const int N = 1005,W = 1e4 + 5;
int n,w,a[N],f[W];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;
    memset(f,0x3f,sizeof(f));
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        f[a[i]] = 1;
    }
    for (int i = 1;i <= w;i++)
        for (int j = 1;j <= n;j++)
            if ((i - a[j]) > 0)
                f[i] = min(f[i],f[i - a[j]] + 1);
    cout << f[w];
    return 0;
}
