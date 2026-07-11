#include<iostream>
using namespace std; const int N = 105;
int n,a[N],fl[N],fr[N],ans = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        fl[i] = fr[i] = 1;
        for (int j = 1;j < i;j++)
            if (a[j] < a[i])
                fl[i] = max(fl[i],fl[j] + 1);
    }
    for (int i = n;i >= 1;i--){
        for (int j = n;j > i;j--)
            if (a[j] < a[i])
                fr[i] = max(fr[i],fr[j] + 1);
        ans = max(ans,fl[i] + fr[i] - 1);
    }
    cout << n - ans;
    return 0;
}