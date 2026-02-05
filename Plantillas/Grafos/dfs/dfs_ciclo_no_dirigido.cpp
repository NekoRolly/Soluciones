#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+4;

int n,m;
vector<int> adj[N];
int vis[N];
bool found;
vector<int> ciclo,rec;

// DFS PARA HALLAR UN CICLO
void dfs(int u,int p){
    vis[u] = 1;
    rec.push_back(u);
    for (int v : adj[u]){
        if (vis[v] == 0)
            dfs(v, u);
        else if (vis[v] == 1 && v != p && !found){
            found = true;
            bool in = false;
            for (int x : rec){
                if (x == v) in = true;
                if (in) ciclo.push_back(x);
            }
        }
    }
    rec.pop_back();
    vis[u] = 2;
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

    for (int i=1; i<=n; i++)
        if (vis[i] == 0)
            dfs(i, -1);

    if (!found)
        cout << "IMPOSSIBLE\n";
    else{
        cout << ciclo.size()+1 << "\n";
        for (int x : ciclo)
            cout << x << " ";
        cout << ciclo[0] << "\n";
    }

    return 0;
}
