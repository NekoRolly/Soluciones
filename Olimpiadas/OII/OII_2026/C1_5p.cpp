// Complejidad  : O(n^2 + 2^n * n)
// Memoria      : O(n)
// Puntaje      : 5 + 0 + 0 + 0 + 0 + 0 = 5
// Idea         : Fuerza Bruta
#include<bits/stdc++.h>
using namespace std;
const int N = 24;
const int inf = 1e9+4;

int n,k;
int h[N],a[N];

void solve(){
    cin >> n >> k;

    for (int i=0; i<n; i++) cin >> h[i];

    for (int i=0; i<n; i++){
        int mxL = h[i], mxR = h[i];
        for (int j=0; j<n; j++){
            if (j < i) mxL = max(mxL, h[j]);
            else if (j > i) mxR = max(mxR, h[j]);
        }
        a[i] = min(mxL, mxR);
    }

    int ans = inf;
    for (int mask=0; mask<(1<<n); mask++){
        int acum = 0, val = 0;
        for (int i=0; i<n; i++){
            if (mask>>i&1){
                val += a[i] - h[i];
                val += max(0, acum - k);
                acum = 0;
            }
            else{
                if (a[i] > h[i]) acum += a[i] - h[i];
                else val += max(0, acum - k), acum = 0;
            }
        }
        ans = min(ans, val);
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int suki; cin >> suki;
    while (suki--) solve();

    return 0;
}
