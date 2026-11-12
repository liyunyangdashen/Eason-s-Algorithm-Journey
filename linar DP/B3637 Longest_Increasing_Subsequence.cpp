#include<iostream>
using namespace std; const int N = 5005;
int n,a[N],f[N],ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        f[i] = 1;
        for (int j = 1;j < i;j++)
            if (a[j] < a[i])
                f[i] = max(f[i],f[j] + 1);
        ans = max(ans,f[i]);
    }
    cout << ans;
    return 0;
}
