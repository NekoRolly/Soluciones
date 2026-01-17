#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+4;

int n,m;
vector<int> adj[N];
int vis[N];
vector<int> topo;
bool found;

void dfs(int u){
    vis[u] = 1;
    for (int v : adj[u]){
        if (vis[v] == 0)
            dfs(v);
        else if (vis[v] == 1)
            found = true;
    }
    vis[u] = 2;
    topo.push_back(u);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i=1; i<=n; i++)
        if (vis[i] == 0)
            dfs(i);

    if (found)
        cout << "IMPOSSIBLE\n";
    else{
        reverse(topo.begin(), topo.end());
        for (int x : topo)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}