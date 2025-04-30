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
 
    pii a[n];
 
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
 
    sort(a, a + n, [](pii a, pii b){
        return a.second < b.second;
    });
 
    int fin = 0;
    int ans = 0;
 
    for (int i=0; i<n; i++){
        if (a[i].first >= fin){
            ans++;
            fin = a[i].second;
        }
    }
 
    cout << ans << "\n";
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
