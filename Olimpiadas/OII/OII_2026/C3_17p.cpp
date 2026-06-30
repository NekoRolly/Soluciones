// Complejidad  : O(n)
// Memoria      : O(n)
// Puntaje      : 0 + 7 + 10 + 0 + 0 + 0 = 17
// Idea         : DP
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+4;
const ll infll = 1e18+4;

int n,k;
int h[N],a[N];
ll dp1[N],dp2[N];

void solve(){
    cin >> n >> k;

    for (int i=1; i<=n; i++) cin >> h[i];

    int mx = 0;
    for (int i=1; i<=n; i++)
        mx = max(mx, h[i]), a[i] = mx;

    mx = 0;
    for (int i=n; i>=1; i--)
        mx = max(mx, h[i]), a[i] = min(a[i], mx);

    dp1[1] = 0, dp2[1] = infll;
    for (int i=2; i<=n; i++){
        dp1[i] = min(dp1[i-1], dp2[i-1]) + a[i] - h[i];
        if (a[i] == h[i]) dp2[i] = infll;
        else dp2[i] = dp1[i-1] + a[i] - h[i] - 1;
    }

    cout << dp1[n] << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int suki; cin >> suki;
    while (suki--) solve();

    return 0;
}
