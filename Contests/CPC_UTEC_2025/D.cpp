#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf = 1e9 + 4;
const ll infll = 1e18 + 4;
const int mod = 1e9 + 7;
const int N = 2e5 + 4;

void solve(){
    int n;
    cin >> n;
    map<int,int> mp1,mp2,mp3,mp4;

    for (int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        mp1[a]++;
        mp2[b]++;
        mp3[a+b]++;
        mp4[a-b]++;
    }

    ll ans = 0;
    for (auto [val, cnt] : mp1)
        ans += 1ll * cnt * (cnt-1);
    for (auto [val, cnt] : mp2)
        ans += 1ll * cnt * (cnt-1);
    for (auto [val, cnt] : mp3)
        ans += 1ll * cnt * (cnt-1);
    for (auto [val, cnt] : mp4)
        ans += 1ll * cnt * (cnt-1);

    cout << ans << "\n";
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