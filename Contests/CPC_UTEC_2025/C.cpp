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

    ll dis[n+1][n+1];
    int a[n+1];

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin >> dis[i][j];

    for (int i=1; i<=n; i++)
        cin >> a[i];

    vector<int> ver;
    vector<ll> vec;
    for (int i=n; i>=1; i--){
        for (int k : ver)
            for (int j : ver){
                dis[j][a[i]] = min(dis[j][a[i]], dis[j][k] + dis[k][a[i]]);
                dis[a[i]][j] = min(dis[a[i]][j], dis[a[i]][k] + dis[k][j]);
            }

        for (int k : ver)
            for (int j : ver)
                dis[k][j] = min(dis[k][j], dis[k][a[i]] + dis[a[i]][j]);

        ver.push_back(a[i]);

        ll ans = 0;
        for (int k : ver)
            for (int j : ver)
                ans += dis[k][j];

        vec.push_back(ans);
    }

    reverse(vec.begin(), vec.end());
    for (ll x : vec)
        cout << x << " ";
    cout << "\n";
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