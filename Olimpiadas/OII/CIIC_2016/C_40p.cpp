#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5+4;
const int mod = 1e9+7;

int n;
vector<pii> adj[N];
ll ans;

void dfs(int u,int p,int beau){
    ans += beau;
    for (auto [v, w] : adj[u])
        if (v != p) dfs(v, u, max(beau, w));
}

/*
Complejidad: O(n^2)
Memoria: O(n)
Puntaje: 20 + 20 + 0 = 40
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i=1; i<n; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i=1; i<=n; i++) dfs(i, -1, 0);

    cout << (ans/2) % mod << '\n';

    return 0;
}
