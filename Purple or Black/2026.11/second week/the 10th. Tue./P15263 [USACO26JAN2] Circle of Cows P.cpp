#include<iostream>
#include<algorithm>
using namespace std; using ll = long long; const int N = 1005;
int n,l,r,cnt = 0; ll c,a[N * 2],ans[N / 2],dis;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> c;
    for (int i = 1;i <= n;i++)
        cin >> a[i]; 
    sort(a + 1,a + n + 1);
    for (int i = 1;i <= n;i++)
        a[i + n] = a[i] + c;
    for (int i = 1;i < n;i++)
        for (int j = i + 1;j <= n;j++){
            l = i + 1; r = j + 1; dis = min(a[j] - a[i],c - (a[j] - a[i])); cnt = 1;
            while (l < j && r < i + n){
                ll len = a[r] - a[l];
                if (len < dis) r++; 
                else if (len > c - dis) l++;
                else cnt++,l++,r++;
            }
            ans[cnt] = max(ans[cnt],dis);
        }
    for (int i = n / 2;i >= 1;i--)
        ans[i] = max(ans[i],ans[i + 1]);
    for (int i = 1;i <= n / 2;i++)
        cout << ans[i] << ' ';
    return 0;
}
