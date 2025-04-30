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

    int a[n];
    int max_subsquence = 0;
    int maxi = -inf;
    int max_subarray = -inf;
    int acum = 0;

    for (int i=0; i<n; i++){
        cin >> a[i];
        maxi = max(maxi, a[i]);

        if (a[i] >= 0)
            max_subsquence += a[i];

        acum = max(acum + a[i], a[i]);
        max_subarray = max(max_subarray, acum);
    }

    cout << max_subarray << " " << (maxi < 0 ? maxi : max_subsquence) << "\n";
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