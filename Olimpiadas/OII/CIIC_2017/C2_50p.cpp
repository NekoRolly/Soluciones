/*
Complejidad: O(n + q*(n+m))
Memoria: O(n+m)
Puntaje: 20 + 30 + 0 = 50
Idea: Optimizar la fuerza bruta por query
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 50004;
const int M = 104;

int n,m,q;
int a[N];
int cnt[M];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    for (int i=1; i<=n; i++) cin >> a[i];

    while (q--){
        int l,r,ans=0,res=0; cin >> l >> r;
        fill(cnt, cnt+m, 0); cnt[0] = 1;
        for (int i=l; i<=r; i++){
            res = (res + a[i])%m;
            ans += cnt[res]++;
        }
        cout << ans << '\n';
    }

    return 0;
}
