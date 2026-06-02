/*
Complejidad: O(n*m + q*m)
Memoria: O(n*m)
Puntaje: 20 + 30 + 50 = 100
Idea: Precalcular y optimizar la fuerza bruta por query
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 50004;
const int M = 104;

int n,m,q;
int a[N],pr[N][M];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    int res = 0; pr[0][0] = 1;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        for (int j=0; j<m; j++)
            pr[i][j] = pr[i-1][j];
        res = (res + a[i]) % m;
        pr[i][res]++;
    }

    while (q--){
        int l,r,ans=0; cin >> l >> r;
        for (int i=0; i<m; i++){
            int cnt = pr[r][i];
            if (l >= 2) cnt -= pr[l-2][i];
            ans += cnt*(cnt-1)/2;
        }
        cout << ans << '\n';
    }

    return 0;
}
