#include<iostream>
//                           MAXN          MAXQ     MAXA
using namespace std; const int N = 2e5 + 5,Q = N,V = 105; 
//                  sparse table,cnt_v_tot,s_cnt_cur
int n,a[N],q,l[Q],r[Q],st[21][N],h[V],sh[N];
int sn[N],sp[N],lp[Q],ls[Q],pos[N],t,lg[N],ans[Q]; 
//    neg,pos,lastpos,lastsum,pos,tot,log2
bool chk(int mid,int id){
    int p = pos[mid],k = lg[r[id] - p + 1],now = ls[id] + sp[p - 1] - sp[lp[id]];
    return now + min(st[k][p],st[k][r[id] - (1 << k) + 1]) - sn[p - 1] >= 0;
}
int bs(int id){
    int L = sh[lp[id]] + 1,R = sh[r[id]] + 1;
    while (L < R){
        int mid = (L + R) >> 1;
        if (mid > sh[r[id]] || chk(mid,id)) R = mid;
        else L = mid + 1;
    }
    return L;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 2;i <= n;i++)
        lg[i] = lg[i / 2] + 1;
    for (int i = 1;i <= n;i++){
        cin >> a[i]; 
        h[a[i]]++;
    }
    cin >> q;
    for (int id = 1;id <= q;id++){
        cin >> l[id] >> r[id];
        lp[id] = l[id] - 1;
    }
    for (int v = 1;v <= V - 5;v++){//v means value
        if (!h[v]) continue;
        t = 0;
        for (int i = 1;i <= n;i++){//shi=屎坨坨;now best before & after
            if (a[i] == v) pos[++t] = i;
            sh[i] = sh[i - 1] + (a[i] == v);
            st[0][i] = sn[i] = sn[i - 1] + (a[i] > v ? a[i] : -a[i]);
            sp[i] = sp[i - 1] + (a[i] >= v ? a[i] : -a[i]);
        }
        for (int j = 1;j <= lg[n];j++)
            for (int i = 1;i + (1 << j) - 1 <= n;i++)
                st[j][i] = min(st[j - 1][i],st[j - 1][i + (1 << (j - 1))]);
        for (int id = 1;id <= q;id++)
            if (sh[r[id]] - sh[l[id] - 1]){
                int res = bs(id);
                ans[id] += max(0,sh[r[id]] - res + 1);
                int nowp = max(lp[id],pos[res - 1]);
                ls[id] += sp[nowp] - sp[lp[id]];
                lp[id] = nowp;
            }
    }
    for (int id = 1;id <= q;id++)
        cout << ans[id] << '\n';
    return 0;
}
