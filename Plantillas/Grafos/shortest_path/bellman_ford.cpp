#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge{
    int u,v,w; // u -w> v
};

const int N = 1004;
const int inf = 1e9+4;

int n,m,q,s;
vector<Edge> edges;
bool check[N]; // TRUE si el vertices se ve afectado por un ciclo negativo
int dis[N];
int up[N]; // para reconstruir el path
vector<int> ciclo;

bool bellman_ford(int s){ // true si hay ciclo negativo
    fill(dis, dis+n, inf);
    fill(up, up+n, -1);
    fill(check, check+n, false);
    dis[s] = 0;
    // cout << "running bellman ford\n";
    int x;
    for (int i=1; i<=2*n; i++){
        // 2*n fases para expandir los verirtices afectados por ciclos negativos
        x = -1;
        for (auto [u, v, w] : edges){
            if (dis[u] < inf && dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                up[v] = u;
                if (i >= n) check[v] = true;
                x = v;
            }
            if (check[u]) check[v] = true;
        }
        // cout << "x: " << x << "\n";
    }

    if (x != -1){ // para hallar un ciclo negativo
        for (int i=0; i<n; i++) x = up[x];
        ciclo.push_back(x);
        for (int u=up[x]; u != x; u=up[u])
            ciclo.push_back(u);
        reverse(ciclo.begin(), ciclo.end());
        // cout << "ciclo: "; for (int u : ciclo) cout << u << " "; cout << "\n";
    }

    return x != -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m >> q >> s && n != 0){
        edges.resize(m);

        for (auto &[u, v, w] : edges)
            cin >> u >> v >> w;

        bellman_ford(s);

        while (q--){
            int u;
            cin >> u;

            if (dis[u] == inf) cout << "Impossible\n";
            else if (check[u]) cout << "-Infinity\n";
            else cout << dis[u] << "\n";
        }
        cout << "\n";
    }

    return 0;
}