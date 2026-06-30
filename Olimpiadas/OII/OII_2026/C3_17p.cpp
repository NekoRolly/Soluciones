// Complejidad  : O(n)
// Memoria      : O(n)
// Puntaje      : 0 + 7 + 10 + 0 + 0 + 0 = 17
// Idea         : Ad Hoc
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int N = 2e6+4;
const ll infll = 1e18+4;

int n,k;
int h[N],a[N];
ll dp[N];
ll pr_a[N],pr_h[N];

ll Agua(int l,int r){
    if (l > r) return 0;
    return (pr_a[r] - pr_a[l-1]) - (pr_h[r] - pr_h[l-1]);
}

void solve(){
    cin >> n >> k;

    for (int i=1; i<=n; i++) cin >> h[i];

    int mx = 0;
    for (int i=1; i<=n; i++)
        mx = max(mx, h[i]), a[i] = mx;

    mx = 0;
    for (int i=n; i>=1; i--)
        mx = max(mx, h[i]), a[i] = min(a[i], mx);

    vector<int> vec;
    for (int i=1; i<=n; i++){
        pr_a[i] = pr_a[i-1] + a[i];
        pr_h[i] = pr_h[i-1] + h[i];
        if (a[i] == h[i]) vec.push_back(i);
    }

    ll ans = 0;
    for (int i=1; i<vec.size(); i++){
        ll A = Agua(vec[i-1]+1, vec[i]-1);
        int len = vec[i] - vec[i-1] - 1;
        ans += A - (len+1)/2;
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int suki; cin >> suki;
    while (suki--) solve();

    return 0;
}
