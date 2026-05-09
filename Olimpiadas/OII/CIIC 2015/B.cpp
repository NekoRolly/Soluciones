#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 1e5+4;

int n,m,L;
vector<pii> in,out;
pii c[N];
int ans[N];
set<pii> st;
int a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> L >> m;

    for (int i=0; i<n; i++){
        int x,p; cin >> x >> p;
        a[i] = x;
        in.push_back({x, i});
        out.push_back({x+p, i});
    }

    for (int i=0; i<m; i++){
        cin >> c[i].first;
        c[i].second = i;
    }

    sort(c, c+m);
    sort(in.begin(), in.end());
    sort(out.begin(), out.end());

    int l = 0, r = 0, cnt = 0;
    for (int i=0; i<m; i++){
        auto [pos, id] = c[i];
        while (l < n && in[l].first <= pos) st.insert(in[l++]);
        for (; r < n && out[r].first < pos; r++) st.erase({a[out[r].second], out[r].second});
        if (!st.empty()) ans[id] = st.rbegin()->second + 1, cnt++;
        else ans[id] = -1;
    }

    cout << cnt << '\n';
    for (int i=0; i<m; i++)
        cout << ans[i] << '\n';

    return 0;
}
