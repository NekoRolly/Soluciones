#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+4;

int n,m;
vector<int> adj[N];
bool vis[N];

void dfs(int u){
    vis[u] = true;

    for (int v : adj[u])
        if (!vis[v])
            dfs(v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    int cnt = 0;

    for (int i=1; i<=n; i++)
        if (!vis[i]){
            cout << i << "\n";
            cnt++;
        }

    if (cnt == 0)
        cout << "Connected\n";

    return 0;
}