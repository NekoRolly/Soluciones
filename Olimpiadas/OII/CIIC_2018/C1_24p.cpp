/*
Complejidad: O(n^2)
Memoria: O(n)
Puntaje: 10 + 14 + 0 + 0 + 0 + 0 = 24
Idea: DFS desde cada vértice
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 500004;

int n,P,k,ans;
int a[N];
vector<int> adj[N];

void dfs(int u,int p,int sum,int rt){
    if (sum == k && u >= rt) ans++;
    for (int v : adj[u])
        if (v != p) dfs(v, u, sum + a[v], rt);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> P >> k; k--;

    for (int i=1; i<=n; i++){
        int x; cin >> x;
        a[i] = x < P;
    }

    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=1; i<=n; i++)
        dfs(i, -1, a[i], i);

    cout << ans << '\n';

    return 0;
}
