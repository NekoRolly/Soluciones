#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+4;

int n,m;
vector<int> adj[N];
bool vis[N];

// DFS PARA RECORRER UN GRAFO
void dfs(int u){
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v])
            dfs(v);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> vec;
    for (int i=1; i<=n; i++)
        if (!vis[i]){
            dfs(i);
            vec.push_back(i);
        }

    cout << vec.size()-1 << "\n";
    for (int i=1; i<vec.size(); i++)
        cout << vec[i-1] << " " << vec[i] << "\n";

    return 0;
}