#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 1e5+4;

int n,m,cnt;
vector<pii> adj[N];
bool vis[N];
ll ans;

void prim_pq(int s){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    fill(vis, vis+n+1, false);
    pq.push({0, s});
    ans = cnt = 0;
    while (!pq.empty()){
        auto [w, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true, ans += w, cnt++;
        for (auto [v, we] : adj[u])
            if (!vis[v])
                pq.push({we, v});
    }
}

void prim_pq_rev(int s){
    priority_queue<pii> pq;
    fill(vis, vis+n+1, false);
    pq.push({0, s});
    ans = cnt = 0;
    while (!pq.empty()){
        auto [w, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true, ans += -w, cnt++;
        for (auto [v, we] : adj[u])
            if (!vis[v])
                pq.push({-we, v});
    }
}

void prim_st(int s){
    set<pii> st;
    fill(vis, vis+n+1, false);
    st.insert({0, s});
    ans = cnt = 0;
    while (!st.empty()){
        auto [w, u] = *st.begin(); st.erase(st.begin());
        if (vis[u]) continue;
        vis[u] = true, ans += w, cnt++;
        for (auto [v, we] : adj[u])
            if (!vis[v])
                st.insert({we, v});
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    prim_st(1);

    if (cnt == n) cout << ans << "\n";
    else cout << "IMPOSSIBLE\n";

    return 0;
}