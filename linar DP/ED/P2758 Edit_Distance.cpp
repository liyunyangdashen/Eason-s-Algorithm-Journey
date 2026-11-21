#include<iostream>
using namespace std; const int N = 2005;
string a,b; int f[N][N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    int lena = a.size(),lenb = b.size();
    a = ' ' + a; b = ' ' + b;
    for (int i = 1;i <= lena;i++) f[i][0] = i;
    for (int j = 1;j <= lenb;j++) f[0][j] = j;
    for (int i = 1;i <= lena;i++)
        for (int j = 1;j <= lenb;j++){
            if (a[i] == b[j])
                f[i][j] = f[i - 1][j - 1];
            else
                f[i][j] = min(f[i][j - 1],min(f[i - 1][j],f[i - 1][j - 1])) + 1;
        }
    cout << f[lena][lenb];
    return 0;
}
