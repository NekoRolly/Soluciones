/*
Complejidad: O(MODlogMOD + q*n*2^n)
Memoria: O(n + MOD)
Puntaje: 6 + 14 + 15 + 0 + 0 = 35
Idea: Precálculo para cada resto y fuerza bruta por consulta
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000003;

int n,q;
int a[25];
int pos[mod];
ll val[mod];

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

    while (q--){
        int k, submask = 0; cin >> k;

        for (int i=0; i<k; i++){
            int x; cin >> x;
            submask ^= 1<<pos[x];
        }

        ll ans = 0;
        for (int mask=0; mask<(1<<n); mask++){
            if ((mask&submask) != submask) continue;
            ll res = 1;
            for (int i=0; i<n; i++)
                if (mask>>i&1) res = (res * a[i]) % mod;
            ans += val[res];
        }

        cout << ans << '\n';
    }

    return 0;
}
