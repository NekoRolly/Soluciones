#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+4;

int n,m;
vector<int> adj[N];
int in_degree[N];
vector<int> topo;

// HALLAR EL TOPOSORT CON KAHN
void kahn(){
    for (int u=1; u<=n; u++)
        for (int v : adj[u])
            in_degree[v]++;

    queue<int> qu;
    for (int i=1; i<=n; i++)
        if (in_degree[i] == 0)
            qu.push(i);

    while (!qu.empty()){
        int u = qu.front();
        qu.pop();
        topo.push_back(u);
        for (int v : adj[u])
            if (--in_degree[v] == 0)
                qu.push(v);
    }
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

    kahn();

    if (topo.size() < n)
        cout << "IMPOSSIBLE\n";
    else{
        for (int x : topo)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}