/*
Complejidad: O(n*logn + q*logn)
Memoria: O(n*logn)
Puntaje: 0 + 0 + 0 + 0 + 15 + 0 = 15
Idea: Hallar el mínimo ancho en un path con Binary Lifting
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 100004;
const int inf = 1000000004;

int n,m,q;
vector<pii> adj[N];
int L[N],R[N],cur;
int pa[N][17],min_w[N][17];

void dfs(int u,int p,int wu){
    L[u] = cur++, pa[u][0] = p, min_w[u][0] = wu;
    for (int i=1; i<17; i++){
        pa[u][i] = pa[pa[u][i-1]][i-1];
        min_w[u][i] = min(min_w[u][i-1], min_w[pa[u][i-1]][i-1]);
    }
    for (auto [v, wv] : adj[u])
        if (v != p) dfs(v, u, wv);
    R[u] = cur;
}

bool isa(int a,int b){
    return L[a] <= L[b] && R[b] <= R[a];
}

int get_min(int a,int b){
    if (isa(a, b)) return inf;
    int mn = inf;
    for (int i=16; i>=0; i--)
        if (!isa(pa[a][i], b)){
            mn = min(mn, min_w[a][i]);
            a = pa[a][i];
        }
    return min(mn, min_w[a][0]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(1, 1, inf);
    cin >> q;

    while (q--){
        int s,t; cin >> s >> t;
        cout << min(get_min(s, t), get_min(t, s)) - 1 << '\n';
    }

    return 0;
}
