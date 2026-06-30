// Complejidad  : O(n)
// Memoria      : O(n)
// Puntaje      : 5 + 7 + 10 + 18 + 25 + 35 = 100
// Idea         : DP + Min Queue / Monotonic Queue
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int N = 2e6+4;
const ll infll = 1e18+4;

struct Min_Queue{
    stack<pll> L,R;

    void push(ll x){
        ll mn = L.empty() ? infll : L.top().second;
        L.push({x, min(x, mn)});
    }

    void pop(){
        if (R.empty()){
            ll mn = infll;
            while (!L.empty()){
                ll x = L.top().first;
                mn = min(mn, x);
                L.pop(); R.push({x, mn});
            }
        }
        R.pop();
    }

    ll get_min(){
        ll mnL = L.empty() ? infll : L.top().second;
        ll mnR = R.empty() ? infll : R.top().second;
        return min(mnL, mnR);
    }

    void clear(){
        while (!L.empty()) L.pop();
        while (!R.empty()) R.pop();
    }
} qu;

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

    for (int i=1; i<=n; i++){
        pr_a[i] = pr_a[i-1] + a[i];
        pr_h[i] = pr_h[i-1] + h[i];
    }

    dp[1] = 0;
    int l = 1, r = 1;
    ll mn = infll;
    qu.clear(); qu.push(dp[1]);
    for (int i=2; i<=n; i++){
        while (Agua(r+1, i-1) > k){
            mn = min(mn, dp[r] - pr_a[r] + pr_h[r]);
            qu.pop(); r++;
        }

        dp[i] = min(mn + pr_a[i-1] - pr_h[i-1] - k, qu.get_min()) + a[i] - h[i];

        if (a[i] == h[i]){
            l = r = i, mn = infll;
            qu.clear();
        }
        qu.push(dp[i]);
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
