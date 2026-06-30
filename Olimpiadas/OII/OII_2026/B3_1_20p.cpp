// Complejidad  : O(n^2)
// Memoria      : O(n)
// Puntaje      : (0 + 0) + (5 + 0) + (15 + 0) + (0 + 0) = 20
// Idea         : DFS + Ad Hoc
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 2004;

void solve_p1(){
}

int n;
vector<int> adj[N];
int impares;
bool flag;

void dfs(int u,int p){
    int hijos = 0, hojas = 0;
    for (int v : adj[u]) if (v != p){
        dfs(v, u); hijos++;
        if (adj[v].size() == 1) hojas++;
    }
    if (hijos&1) impares++;
    if (hijos > 2*hojas) flag = false;
}

void solve_p2(){
    cin >> n;

    for (int i=1; i<=n; i++) adj[i].clear();

    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u=1; u<=n; u++){
        impares = 0, flag = true; dfs(u, -1);
        if (flag && impares == (n-1)%2){
            cout << "YES\n";
            for (int i=1; i<n; i++)
                cout << "1 1\n";
            return;
        }
    }

    cout << "NO\n";
}

void solve(){
    int p; cin >> p;
    if (p == 1) solve_p1();
    else solve_p2();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int suki; cin >> suki;
    while (suki--) solve();

    return 0;
}
