/*
Complejidad: O(n + m + q*(n+m)*logm)
Memoria: O(n + m)
Puntaje: 7 + 13 + 15 + 15 + 0 + 0 = 50
Idea: Greedy y fuerza bruta por cada query
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 100004;
const int inf = 1000000004;

int n,m,q;
vector<pii> adj[N];
int val[N];
priority_queue<pii> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cin >> q;

    while (q--){
        int s,t; cin >> s >> t;
        fill(val+1, val+n+1, 0);
        pq.push({inf, s});
        while (!pq.empty()){
            auto [mn, u] = pq.top(); pq.pop();
            if (val[u] != 0) continue;
            val[u] = mn;
            for (auto [v, wv] : adj[u])
                if (val[v] == 0) pq.push({min(mn, wv), v});
        }
        cout << val[t] - 1 << '\n';
    }

    return 0;
}
