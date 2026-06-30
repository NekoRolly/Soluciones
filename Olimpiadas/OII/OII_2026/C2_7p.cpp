// Complejidad  : O(n)
// Memoria      : O(n)
// Puntaje      : 0 + 7 + 0 + 0 + 0 + 0 = 7
// Idea         : Ad Hoc
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+4;

int n,k;
int h[N];
vector<int> vec;

void solve(){
    cin >> n >> k;

    vec.clear();
    for (int i=0; i<n; i++){
        cin >> h[i];
        if (h[i] > 0) vec.push_back(i);
    }

    ll ans = 0;
    for (int i=1; i<vec.size(); i++){
        int len = vec[i] - vec[i-1] - 1, H = h[vec[i]];
        ans += 1ll * len * H - (len+1)/2;
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int suki; cin >> suki;
    while (suki--) solve();

    return 0;
}
