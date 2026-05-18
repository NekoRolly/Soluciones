#include "garden.h"
#include "gardenlib.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 300004;
const int inf = 1e9+4;

int n,m,p;
vector<int> adj[N];
vector<int> _adj[N];
int nxt[N];
bool vis[N];
int ciclo[N],cur;
int sz_ciclo[N];
int dis1[N],dis2[N];

void dfs(int u,int Dis,int dis[]){
    dis[u] = Dis, vis[u] = true;
    for (int v : _adj[u])
        if (!vis[v]) dfs(v, Dis+1, dis);
}

bool check(int a,int b,int k,int dis[]){
    if (dis[a] == -1 || k < dis[a]) return false;
    if (ciclo[b] == 0) return k == dis[a];
    int res = k - dis[a];
    return res%sz_ciclo[ciclo[b]] == 0;
}

void count_routes(int _n, int _m, int _p, int R[][2], int q, int G[]){
    n = _n, m = _m, p = _p;

    for (int i=0; i<m; i++){
        int u = R[i][0], v = R[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=0; i<n; i++){
        nxt[i] = adj[i][0];
        if (adj[adj[i][0]][0] == i) nxt[i] += n;
        if (adj[i].size() == 1){
            nxt[i+n] = adj[i][0];
            if (adj[adj[i][0]][0] == i) nxt[i+n] += n;
        }
        else{
            nxt[i+n] = adj[i][1];
            if (adj[adj[i][1]][0] == i) nxt[i+n] += n;
        }
        // cout << i << " -> " << nxt[i][0] << '\n';
        // cout << i+n << " -> " << nxt[i+n][0] << '\n';
        _adj[nxt[i]].push_back(i);
        _adj[nxt[i+n]].push_back(i+n);
    }

    for (int i=0,j; i<2*n; i++){
        if (vis[i]) continue;
        vector<int> vec;
        for (j=i; !vis[j]; j=nxt[j]){
            vis[j] = true;
            vec.push_back(j);
        }
        bool flag = false;
        for (int x : vec){
            if (x == j) flag = true, cur++;
            if (flag) ciclo[x] = cur, sz_ciclo[cur]++;
        }
    }

    fill(dis1, dis1+2*n, -1);
    fill(vis, vis+2*n, false);
    dfs(p, 0, dis1);
    fill(dis2, dis2+2*n, -1);
    fill(vis, vis+2*n, false);
    dfs(p+n, 0, dis2);

    for (int i=0; i<q; i++){
        int ans = 0, k = G[i];
        for (int j=0; j<n; j++){
            ans += check(j, p, k, dis1) + check(j, p+n, k, dis2);
        }
        answer(ans);
    }
}
