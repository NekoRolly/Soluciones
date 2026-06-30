// Complejidad  : O(n^2)
// Memoria      : O(n)
// Puntaje      : 5 + 0 + 0 + 18 + 25 + 0 = 48
// Idea         : DP
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+4;
const ll infll = 1e18+4;

int n,k;
int h[N],a[N];
ll dp[N];

void solve(){
    cin >> n >> k;

    for (int i=1; i<=n; i++) cin >> h[i];

    int mx = 0;
    for (int i=1; i<=n; i++)
        mx = max(mx, h[i]), a[i] = mx;

    mx = 0;
    for (int i=n; i>=1; i--)
        mx = max(mx, h[i]), a[i] = min(a[i], mx);

    dp[1] = 0;
    for (int i=2; i<=n; i++){
        ll total = 0; dp[i] = infll;
        for (int j=i-1; j>=1; j--){
            dp[i] = min(dp[i], dp[j] + max(0ll, total - k) + a[i] - h[i]);
            if (a[j] == h[j]) break;
            total += a[j] - h[j];
        }
    }

    cout << dp[n] << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int suki; cin >> suki;
    while (suki--) solve();

    return 0;
}
