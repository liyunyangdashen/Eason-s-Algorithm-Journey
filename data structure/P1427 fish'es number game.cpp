#include<iostream>
#include<stack>
using namespace std;
int x; stack<int> s;
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    while (cin >> x){
        if (!x) break;
        s.push(x);
    }
    while (!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
    return 0;
}
