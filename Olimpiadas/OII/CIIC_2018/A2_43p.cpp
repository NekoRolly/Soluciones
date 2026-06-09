/*
Complejidad: O(n^2 * 2^n)
Memoria: O(n)
Puntaje: 0 + 43 + 0 = 43
Idea: fuerza bruta con bitmask
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+4;

int n,ans;
int a[2*N],b[2*N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i=0; i<2*n; i++) cin >> a[i];

    for (int mask=0; mask<(1<<(n+1)); mask++){
        for (int i=0; i<2*n; i++) b[i] = a[i];
        for (int i=0; i<=n; i++) if (mask>>i&1){
            for (int j=i; j<i+n; j++) b[j] = -b[j];
        }
        int val = 0;
        for (int i=0; i<2*n; i++) val += b[i];
        ans = max(ans, val);
    }
    cout << ans << '\n';

    return 0;
}
