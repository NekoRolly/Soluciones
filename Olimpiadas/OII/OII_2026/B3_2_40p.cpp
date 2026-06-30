// Complejidad  : O(n^2)
// Memoria      : O(n)
// Puntaje      : (0 + 0) + (5 + 5) + (15 + 15) + (0 + 0) = 40
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

vector<pii> vecL,vecR;
pii aux;

void dfs1(int u,int p){
    vector<int> vL,vR;
    for (int v : adj[u]) if (v != p){
        if (adj[v].size() == 1) vR.push_back(v);
        else vL.push_back(v);
    }
    while (vR.size() - vL.size() >= 2){
        vL.push_back(vR.back());
        vR.pop_back();
    }
    if (vR.size() > vL.size()){
        aux = {u, vR.back()};
        vR.pop_back();
    }
    for (int v : vL) vecL.push_back({u, v});
    for (int v : vR) vecR.push_back({u, v});
    for (int v : vL) dfs1(v, u);
}

void solve_p2(){
    cin >> n;

    for (int i=1; i<=n; i++) adj[i].clear();

    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int rt = -1;
    for (int u=1; u<=n; u++){
        impares = 0, flag = true; dfs(u, -1);
        if (flag && impares == (n-1)%2) rt = u;
    }

    if (rt == -1) cout << "NO\n";
    else{
        cout << "YES\n";
        vecL.clear(), vecR.clear();
        dfs1(rt, -1);
        if ((n-1)%2 == 1) vecL.push_back(aux);
        while (!vecR.empty()){
            vecL.push_back(vecR.back());
            vecR.pop_back();
        }
        for (auto [u, v] : vecL) cout << u << " " << v << "\n";
    }
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
