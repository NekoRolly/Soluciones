#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll infll = 1e18+4;
const int N = 504;

ll dis[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,q;
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

    for (int k=1; k<=n; k++)
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    while (q--){
        int a,b;
        cin >> a >> b;
        cout << (dis[a][b] == infll ? -1 : dis[a][b]) << "\n";
    }

    return 0;
}