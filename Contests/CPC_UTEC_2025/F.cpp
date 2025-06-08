#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf = 1e9 + 4;
const ll infll = 1e18 + 4;
const int mod = 1e9 + 7;
const int N = 1e6 + 4;

void solve(){
    int n;
    cin >> n;
    int h[n+1][n+1];
    int a[n+1],b[n+1];

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++)
            cin >> h[i][j];
    }

    for (int i=1; i<=n; i++)
        cin >> a[i];

    for (int i=1; i<=n; i++)
        cin >> b[i];

    ll dp[n+1][2];
    for (int i=2; i<=n; i++)
        dp[i][0] = dp[i][1] = infll;
    dp[1][0] = 0;
    dp[1][1] = a[1];

    for (int i=2; i<=n; i++){
        bool t1,t2,t3;
        t1 = t2 = t3 = false;
        for (int j=1; j<=n; j++){
            t1 |= (h[i-1][j] + 1 == h[i][j]);
            t2 |= (h[i-1][j] == h[i][j] + 1);
            t3 |= (h[i-1][j] == h[i][j]);
        }

        if (!t3){
            dp[i][1] = min(dp[i][1], dp[i-1][1] + a[i]);
            dp[i][0] = min(dp[i][0], dp[i-1][0]);
        }
        if (!t2){
            dp[i][1] = min(dp[i][1], dp[i-1][0] + a[i]);
        }
        if (!t1){
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
        }
    }

    ll ans = min(dp[n][0], dp[n][1]);
    // cout << ans << "\n";

    for (int i=2; i<=n; i++)
        dp[i][0] = dp[i][1] = infll;
    dp[1][0] = 0;
    dp[1][1] = b[1];

    for (int i=2; i<=n; i++){
        bool t1,t2,t3;
        t1 = t2 = t3 = false;
        for (int j=1; j<=n; j++){
            t1 |= (h[j][i-1] + 1 == h[j][i]);
            t2 |= (h[j][i-1] == h[j][i] + 1);
            t3 |= (h[j][i-1] == h[j][i]);
        }

        if (!t3){
            dp[i][1] = min(dp[i][1], dp[i-1][1] + b[i]);
            dp[i][0] = min(dp[i][0], dp[i-1][0]);
        }
        if (!t2){
            dp[i][1] = min(dp[i][1], dp[i-1][0] + b[i]);
        }
        if (!t1){
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
        }
    }

    ans += min(dp[n][1], dp[n][0]);

    cout << (ans >= infll ? -1 : ans) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int kou = 1;
    cin >> kou;

    while (kou--)
        solve();

    return 0;
}