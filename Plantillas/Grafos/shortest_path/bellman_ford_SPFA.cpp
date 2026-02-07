#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1004;
const int inf = 1e9+4;

int n,m,q,s;
vector<pair<int,int>> adj[N];
int dis[N];
int up[N]; // para reconstruir el path
int cnt[N]; // cuenta la cantidad de mejoras del shortest path de i

// SPFA : Shortest Path Faster Algorithm
void SPFA(int s){
    fill(dis, dis+n, inf);
    fill(up, up+n, -1);
    fill(cnt, cnt+n, 0);

    dis[s] = 0;
    queue<int> qu;
    qu.push(s);

    while (!qu.empty()){
        int u = qu.front();
        qu.pop();

        for (auto [v, w] : adj[u])
            if (dis[v] != -inf && dis[v] > dis[u] + w){
                cnt[v]++;
                dis[v] = cnt[v] >= n || dis[u] == -inf ? -inf : dis[u] + w;
                up[v] = u;
                qu.push(v);
            }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m >> q >> s && n != 0){

        for (int i=0; i<n; i++)
            adj[i].clear();

        for (int i=0; i<m; i++){
            int u,v,w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }

        SPFA(s);
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
