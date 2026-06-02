/*
Complejidad: O(n + q*n^2)
Memoria: O(n)
Puntaje: 20 + 0 + 0 = 20
Idea: Fuerza Bruta por query
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 50004;

int n,m,q;
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    for (int i=1; i<=n; i++) cin >> a[i];

    while (q--){
        int l,r,ans=0; cin >> l >> r;
        for (int i=l; i<=r; i++){
            int res = 0;
            for (int j=i; j<=r; j++){
                res = (res + a[j])%m;
                if (res == 0) ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
