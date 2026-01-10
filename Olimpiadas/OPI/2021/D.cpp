#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 54;
const int M = 2504;
const int inf = 1e9+4;
const bool debug = false;

int n,m;

vector<int> adj_C[N],adj_J[N],adj_B[N];

struct Estado{
    int c,j,b;
};

vector<int> _adj[N];
vector<int> topo; // toposort para hallar alturas
vector<Estado> est[N];
int h[N]; // alturas asignadas
bool vis[N];

bool is_path_C[N][N];
bool is_path_J[N][N];
bool is_path_B[N][N];

int dp[N][N][N];

void _dfs(int u){
    vis[u] = true;
    for (int v : _adj[u])
        if (!vis[v])
            _dfs(v);
    if (!topo.empty() || u == 1)
        topo.push_back(u);
}

void dfs_X(int u,vector<int> adj[],bool is_path[][N],int rt){
    vis[u] = true;
    is_path[rt][u] = true;
    for (int v : adj[u])
        if (!vis[v])
            dfs_X(v, adj, is_path, rt);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        int E;
        cin >> E;
        for (int j=0; j<E; j++){
            int u,v; // u -> v
            cin >> u >> v;

            if (i == 0) adj_C[u].push_back(v);
            else if (i == 1) adj_J[u].push_back(v);
            else adj_B[u].push_back(v);

            _adj[v].push_back(u);
        }
    }

    // para evitar que se rompa el dp
    adj_C[1].push_back(1);
    adj_J[1].push_back(1);
    adj_B[1].push_back(1);

    _dfs(n);

    if (debug){
        cout << "topo: ";
        for (int x : topo)
            cout << x << " ";
        cout << "\n";
    }

    int cur = 0;
    for (int x : topo){
        h[x] = cur++; // asignamos alturas para trabajar en orden
        for (int i=1; i<=n; i++)
            if (i != x && x != 1){
                est[h[x]].push_back({x, x, i});
                est[h[x]].push_back({x, i, x});
                est[h[x]].push_back({i, x, x});
            }
        est[h[x]].push_back({x, x, x});
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++)
            vis[j] = false;
        dfs_X(i, adj_C, is_path_C, i);
        for (int j=1; j<=n; j++)
            vis[j] = false;
        dfs_X(i, adj_J, is_path_J, i);
        for (int j=1; j<=n; j++)
            vis[j] = false;
        dfs_X(i, adj_B, is_path_B, i);
    }

    dp[1][1][1] = 1;
    for (int i=1; i<int(topo.size()); i++){
        for (Estado e : est[i]){
            dp[e.c][e.j][e.b] = -inf;
            for (int j=0; j<i; j++){
                for (Estado f : est[j]){ // O(n^4)
                    if (is_path_C[f.c][e.c] && is_path_J[f.j][e.j] && is_path_B[f.b][e.b])
                        dp[e.c][e.j][e.b] = max(dp[e.c][e.j][e.b], dp[f.c][f.j][f.b] + 1);
                }
            }
            if (debug)
                cout << "dp " << e.c << " " << e.j << " " << e.b << " " << dp[e.c][e.j][e.b] << "\n";
        }
    }

    cout << dp[n][n][m == 2 ? 1 : n] << "\n";

    return 0;
}
