#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    map<string,int> mp;

    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            string t = s.substr(i, j-i+1);
            sort(t.begin(), t.end());
            t.erase(unique(t.begin(), t.end()), t.end());
            mp[t] = max(mp[t], j-i+1);
        }
    }

    ll ans = 0;
    for (auto [t, len] : mp)
        ans += t.size() * len;
    
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