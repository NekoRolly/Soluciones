#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 2e5+1;

ll n,m;
vector<pair<int,int>> rn;
vector<pair<int,int>> ans;
int t[M];
int al,ar;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<n; i++){
        int l,r; cin >> l >> r;
        rn.push_back({l, r});
    }
    for (int i=1; i<=m; i++) cin >> t[i];

    al = ar = t[1];

    for (int i=2; i<=m; i++){
        if (t[i] > t[i-1]+1){
            rn.push_back({al, ar});
            al = ar = t[i];
        }
        else ar++;
    }

    if (m) rn.push_back({al, ar});

    sort(rn.begin(), rn.end());

    n = rn.size();
    if (n) al = rn[0].first, ar = rn[0].second;

    for (int i=1; i<n; i++){
        if (rn[i].first > ar+1){
            ans.push_back({al, ar});
            al = rn[i].first, ar = rn[i].second;
        }
        else ar = max(ar, rn[i].second);
    }

    if (n) ans.push_back({al, ar});

    cout << ans.size() << "\n";
    for (auto x : ans) cout << x.first << " " << x.second << "\n";

    return 0;
}