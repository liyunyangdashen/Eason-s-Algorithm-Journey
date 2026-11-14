#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std; using ll = long long; const int N = 5005,W = N;
int t,n,k,w[N]; ll m,nd; bool ans[N][N]; vector<int> h[N]; queue<int> rd;
ll maxC(ll k){return k * (k * k - (k % 2 ? 1 : 4)) / 24;}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--){
        cin >> n >> m;
        k = 1;
        while (k <= n && maxC(k) < m)
            k++;
        if (k > n){
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        memset(w,0,sizeof(w));
        for (int i = 0;i < n;i++) h[i].clear();
        while (!rd.empty()) rd.pop();
        for (int i = 1;i <= k;i++)
            for (int j = i + 1;j <= k;j++){
                ans[i][j] = (j - i <= k / 2);
                ans[j][i] = !ans[i][j];
                w[i] += ans[i][j];
                w[j] += ans[j][i];
            }
        for (int i = 1;i <= k;i++)//i->id
            h[w[i]].push_back(i);
        for (int d = 0;d < k;d++)//d->win
            if (h[d].size() >= 2)
                rd.push(d);
        nd = maxC(k) - m;
        while (nd){
            int d = rd.front();
            rd.pop();
            if (h[d].size() < 2) continue;
            int x = h[d].back();
            h[d].pop_back();
            int y = h[d].back();
            h[d].pop_back();
            if (!ans[x][y]) swap(x,y);
            ans[x][y] = 0,ans[y][x] = 1;
            w[x]--,w[y]++;
            h[d - 1].push_back(x);
            h[d + 1].push_back(y);
            if (h[d - 1].size() == 2)
                rd.push(d - 1);
            if (h[d + 1].size() == 2)
                rd.push(d + 1);
            if (h[d].size() >= 2)
                rd.push(d);
            nd--;
        }
        for (int i = k + 1;i <= n;i++)
            for (int j = 1;j < i;j++)
                ans[i][j] = 1, ans[j][i] = 0;
        for (int i = 2;i <= n;i++){
            for (int j = 1;j < i;j++)
                cout << ans[i][j];
            cout << '\n';
        }
    }
    return 0;
}
//(C(d - 1,2) + C(d + 1,2)) - 2 * C(d,2) = 1,0~max always true
