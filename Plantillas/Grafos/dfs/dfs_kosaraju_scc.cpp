#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 5e5+4;

int n,m;
vector<int> adj[N],adjR[N];
vector<int> topo;
bool vis[N];
int col[N],cur;
vector<int> comp[N];

void dfs1(int u){
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v]) dfs1(v);
    topo.push_back(u);
}

void dfs2(int u,int c){
    col[u] = c;
    for (int v : adjR[u])
        if (col[v] == 0) dfs2(v, c);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adjR[b].push_back(a);
    }

    for (int i=0; i<n; i++)
        if (!vis[i]) dfs1(i);

    reverse(topo.begin(), topo.end());
    for (int u : topo)
        if (col[u] == 0) dfs2(u, ++cur);

    for (int i=0; i<n; i++)
        comp[col[i]].push_back(i);

    cout << cur << "\n";
    for (int i=1; i<=cur; i++){
        cout << comp[i].size();
        for (int x : comp[i]) cout << " " << x;
        cout << "\n";
    }

    return 0;
}