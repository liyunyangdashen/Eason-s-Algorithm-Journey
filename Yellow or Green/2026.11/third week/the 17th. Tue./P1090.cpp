#include<iostream>
#include<queue>
#include<vector>
using namespace std; 
int n,x,ans = 0; priority_queue<int,vector<int>,greater<int> > pq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> x;
        pq.push(x);
    }
    while (pq.size() - 1){
        int u = pq.top();
        pq.pop();
        int v = pq.top();
        pq.pop();
        pq.push(u + v);
        ans += u + v;
    }
    cout << ans;
    return 0;
}
