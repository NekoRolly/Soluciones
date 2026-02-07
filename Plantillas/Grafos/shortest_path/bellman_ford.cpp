#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1004;
const int inf = 1e9+4;

struct Edge{
    int u,v,w; // u ---w---> v
};

int n,m,q,s;
vector<Edge> edges;
int dis[N];
int up[N]; // para reconstruir el path

void bellman_ford(int s){
    fill(dis, dis+n, inf);
    fill(up, up+n, -1);
    dis[s] = 0;

    for (int i=1; i<2*n; i++){
        // n-1 fases para hallar los shortest paths
        // n fases para detectar los vertices sin shortest path
        bool flag = false;
        for (auto [u, v, w] : edges){
            if (dis[u] < inf && dis[v] > dis[u] + w){
                up[v] = u;
                dis[v] = i >= n ? -inf : dis[u] + w;
                flag = true;
            }
        }
        // flag = false si no hubo cambio
        if (!flag) break;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m >> q >> s && n != 0){
        edges.resize(m);

        for (auto &[u, v, w] : edges)
            cin >> u >> v >> w;

        bellman_ford(s);
        // if dis[i] = inf, entonces no hay path de s a i
        // else if dis[i] = -inf, entonces no existe shortest path de s a i
        // else dis[i] es el shortest path de s a i

        while (q--){
            int u;
            cin >> u;

            if (dis[u] == inf) cout << "Impossible\n";
            else if (dis[u] == -inf) cout << "-Infinity\n";
            else cout << dis[u] << "\n";
        }
        cout << "\n";
    }

    return 0;
}
