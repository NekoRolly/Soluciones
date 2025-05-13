#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf = 1e9 + 4;
const ll infll = 1e18 + 4;
const int mod = 1e9 + 7;
const int N = 1e5 + 4;

int n;
int h[N];
int dp[N];

void solve(){
    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> h[i];
        dp[i] = -1;
    }

    dp[1] = 0;
    dp[2] = abs(h[1] - h[2]);

    for (int i=3; i<=n; i++){
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }

    cout << dp[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int kou = 1;
    // cin >> kou;

    while (kou--)
        solve();

    return 0;
}