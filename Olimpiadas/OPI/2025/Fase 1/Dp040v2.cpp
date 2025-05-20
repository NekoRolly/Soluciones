#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    map<string,int> mp;

    for (int i=0; i<n; i++){
        int cnt[26]={0};
        string t;
        for (int j=i; j<n; j++){
            int x = s[j]-'a';
            cnt[x]++;
            if (cnt[x] == 1){
                t.push_back(s[j]);
                sort(t.begin(), t.end());
            }
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