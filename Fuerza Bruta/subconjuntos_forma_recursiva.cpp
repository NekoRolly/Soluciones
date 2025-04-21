#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf = 1e9 + 4;
const ll infll = 1e18 + 4;
const int mod = 1e9 + 7;
const int N = 2e5 + 4;

int n;
int a[24];
ll sum_total;
ll min_diff = infll;

void get_subsets(int i,ll sum){
    if (i == n){
        ll otro_sum = sum_total - sum;
        min_diff = min(min_diff, abs(sum - otro_sum));
        return;
    }

    get_subsets(i + 1, sum + a[i]);
    get_subsets(i + 1, sum);
}

void solve(){
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> a[i];
        sum_total += a[i];
    }

    get_subsets(0, 0);

    cout << min_diff << '\n';
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