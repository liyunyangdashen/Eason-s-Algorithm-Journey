#include<iostream>
#include<cstring>
#include<cmath>
using namespace std; using i128 = __int128_t; const int N = 85;
int m,n,a[N]; i128 ans = 0,p2[N],f[N][N]; //2^64 < 1000 * 2^80 < 2^128,use i128
void print(__int128 x) {
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    p2[0] = 1;
    for (int i = 1;i <= n;i++)
        p2[i] = 2 * p2[i - 1];//p2
    for (int i = 1;i <= m;i++){
        for (int i = 1;i <= n;i++){
            cin >> a[i];
            f[i][i] = a[i] * p2[n];//use p2[] instead of pow, pow is double not i128
        }
        //f,not0x3f;but it should be -0x3f not 0x3f,cause max not min；demo,no memset at total
        for (int len = 2;len <= n;len++)
            for (int i = 1;i <= n - len + 1;i++){
                int j = i + len - 1;//also pow->p2[]
                f[i][j] = max(f[i + 1][j] + a[i] * p2[n - len + 1],f[i][j - 1] + a[j] * p2[n - len + 1]);
            }
        ans += f[1][n];
    }
    print(ans);
    return 0;
}
