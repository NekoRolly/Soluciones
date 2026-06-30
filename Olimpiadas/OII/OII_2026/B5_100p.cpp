// Complejidad  : O(n) + O(n)
// Memoria      : O(1) + O(n)
// Puntaje      : (9 + 21) + (5 + 5) + (15 + 15) + (15 + 15) = 100
// Idea         : Ad Hoc + DFS
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 200004;

void solve_p1(){
    int n,d; cin >> n >> d;
    int k = n/2;
 
    if (d == 1){
        if (n == 2) cout << "YES\n1 2\n";
        else cout << "NO\n";
        return;
    }
 
    if (d > k+1){ cout << "NO\n"; return;}
    cout << "YES\n";
 
    for (int i=2,p; i<=n; i++){
        if (i <= d) p = i-1;
        else if (i >= n+1-(d-1)) p = n+1-i;
        else p = 1;
        cout << p << ' ' << i << '\n';
    }
}

int n;
vector<int> adj[N];
int Impares;
int hojas[N];
bool valid[N];
int cnt_valid;

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

    cnt_valid = Impares = 0;
    for (int i=1; i<=n; i++){
        adj[i].clear();
        hojas[i] = 0, valid[i] = false;
    }

    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u=1; u<=n; u++){
        int hijos = adj[u].size()-1;
        if (hijos%2 == 1) Impares++;
        for (int v : adj[u]) 
            if (adj[v].size() == 1) hojas[u]++;
        if (2*hojas[u] >= hijos)
            valid[u] = true, cnt_valid++;
    }
    
    int rt = -1;
    for (int u=1; u<=n; u++){
        int hijos = adj[u].size();
        int impares = Impares, cnt = cnt_valid;
        cnt -= valid[u];
        if (hijos <= 2*hojas[u]) cnt++;
        if (hijos%2 == 1) impares++;
        else impares--;
        if (adj[u].size() == 1){
            int v = adj[u][0];
            cnt -= valid[v];
            if (2*(hojas[v]-1) >= adj[v].size()-1) cnt++;
        }
        if (cnt == n && impares == (n-1)%2) rt = u;
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
