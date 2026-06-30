// Complejidad  : O(n)
// Memoria      : O(n)
// Puntaje      : (0 + 0) + (5 + 0) + (15 + 0) + (15 + 0) = 35
// Idea         : Ad Hoc
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 200004;

void solve_p1(){
}

int n;
vector<int> adj[N];
int Impares;
int hojas[N];
bool valid[N];
int cnt_valid;

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
        if (cnt == n && impares == (n-1)%2){
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
