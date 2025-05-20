#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll H = 1<<26;
vector<pair<int,int>> vec;
vector<ll> v;
int pos[26];

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    v.clear();

    for (int i=0; i<26; i++)
        pos[i] = n;

    vec = {{n, -1}};
    for (int i=n-1; i>=0; i--){
        int x = s[i]-'a';
        if (pos[x] < n){
            int j = 0;
            while (vec[j].second != x) j++;
            vec.erase(vec.begin() + j);
        }
        pos[x] = i;
        vec.insert(vec.begin(), {i, x});

        int mask = 0;
        for (auto [r, b] : vec){
            if (mask > 0)
                v.push_back(H*mask+r-i);
            if (b != -1)
                mask |= 1<<b;
        }
    }

    sort(v.begin(), v.end());
    ll ans = 0, cnt = 0;
    for (int i=0; i<v.size(); i++){
        int mask = v[i]/H, len = v[i]%H;
        if (i+1 == v.size() || v[i+1]/H != mask){
            ans += __builtin_popcount(mask) * len;
            cnt++;
        }
    }
    
    cout << cnt << " " << ans << "\n";
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