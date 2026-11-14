#include<iostream>
#include<algorithm>
using namespace std; using ll = long long; using pll = pair<ll,ll>; const int N = 5e5 + 5;
int n,id[N]; pll v[N],sx,sy; bool gv,hv[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++)
        cin >> v[i].first,id[i] = i;
    for (int i = 1;i <= n;i++)
        cin >> v[i].second;
    sort(id + 1,id + n + 1,[](int x,int y){return v[x].first > v[y].first;});
    for (int i = 1;i <= n;i++){
        int p = id[i];
        if (sx.first <= sy.first)
            sx.first += v[p].first,
            sx.second += v[p].second,
            hv[p] = 0;
        else
            sy.first += v[p].first,
            sy.second += v[p].second,
            hv[p] = 1;
    }
    gv = (sx.second >= sy.second);
    for (int i = 1;i <= n;i++)
        cout << (hv[i] ^ gv) << ' ';
    return 0;
}
