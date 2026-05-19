#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+4;

int n,m;
int cnt[N];
/*
Complejidad: O(n*m)
Memoria: O(n)
Puntaje: 0 + 30 + 0 = 30
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        int l,r; cin >> l >> r;
        for (int j=l; j<=r; j++) cnt[j]++;
    }

    int ans = 0;
    for (int i=1; i<=n; i++)
        ans = max(ans, cnt[i]);
    cout << ans << '\n';

    return 0;
}
