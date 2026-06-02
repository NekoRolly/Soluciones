/*
Complejidad: O(MODlogMOD + n*2^n + q*n)
Memoria: O(MOD + 2^n)
Puntaje: 6 + 14 + 15 + 25 + 40 = 100
Idea: Precálculo para cada resto y máscara con DP SOS
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000003;

int n,q;
int a[22];
int pos[mod];
ll val[mod],dp[1<<22];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (ll i=1; i<mod; i++)
        for (int j=2*i; j<mod; j+=i)
            val[j] += i*i;

    cin >> n >> q;

    for (int i=0; i<n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }

    for (int mask=0; mask<(1<<n); mask++){
        ll res = 1;
        for (int i=0; i<n; i++)
            if (mask>>i&1) res = (res * a[i])%mod;
        dp[mask] = val[res];
    }

    for (int i=0; i<n; i++)
        for (int mask=0; mask<(1<<n); mask++)
            if (mask>>i&1^1) dp[mask] += dp[mask^(1<<i)];

    while (q--){
        int k, mask = 0; cin >> k;

        for (int i=0; i<k; i++){
            int x; cin >> x;
            mask ^= 1<<pos[x];
        }

        cout << dp[mask] << '\n';
    }

    return 0;
}
