// Complejidad  : O(n! * n^2)
// Memoria      : O(n^2)
// Puntaje      : (0 + 0) + (5 + 5) + (0 + 0) + (0 + 0) = 10
// Idea         : Fuerza Bruta
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 10;

void solve_p1(){
}

int n;
bool adj[N][N];
int p[N];

void solve_p2(){
    cin >> n;

    for (int i=1; i<=n; i++){
        fill(adj[i]+1, adj[i]+n+1, false);
        p[i] = i;
    }

    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u][v] = adj[v][u] = true;
    }

    do{
        vector<pii> vec;
        for (int i=2; i<=n; i++){
            int pa = -1;
            for (int j=1; j<i; j++)
                if (adj[p[j]][p[i]]) pa = p[j];
            vec.push_back({pa, p[i]});
        }
        bool flag = true;
        for (int i=0; i<n-1; i++){
            if (vec[i].first == -1) flag = false;
            if (vec[i].first != vec[n-2-i].first) flag = false;
        }
        if (flag){
            cout << "YES\n";
            for (auto [u, v] : vec) cout << u << " " << v << "\n";
            return;
        }
    } while (next_permutation(p+1, p+n+1));

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
