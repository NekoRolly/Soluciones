#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    map<int,int> mp;

    for (int i=0; i<n; i++){
        int mask=0;
        for (int j=i; j<n; j++){
            int x = s[j]-'a';
            mask |= 1<<x;
            mp[mask] = max(mp[mask], j-i+1);
        }
    }

    ll ans = 0;
    for (auto [mask, len] : mp)
        ans += __builtin_popcount(mask) * len;
    
    cout << mp.size() << " " << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}