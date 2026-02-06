#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll infll = 1e18+4;
const int N = 504;

ll dis[N][N];
int n,m,q;


bool check(int u,int v){
    // TRUE si hay un ciclo negativo en algún camino de u a v
    // no existe shortest path entre u y v
    for (int t=1; t<=n; t++)
        if (dis[u][t] < infll && dis[t][t] < 0 && dis[t][v] < infll)
            return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (i != j) dis[i][j] = infll;
        
    while (m--){
        ll u,v,w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }

    // floyd warshall con pesos negativos
    for (int k=1; k<=n; k++)
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                if (dis[i][k] < infll && dis[k][j] < infll)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    while (q--){
        int a,b;
        cin >> a >> b;
        cout << (dis[a][b] == infll ? -1 : dis[a][b]) << "\n";
    }

    return 0;
}