#include "garden.h"
#include "gardenlib.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 150004;
const int inf = 1e9+4;

int n,m,p;
vector<int> adj[N];
int nxt[2*N][30];

void count_routes(int _n, int _m, int _p, int R[][2], int q, int G[]){
    n = _n, m = _m, p = _p;

    for (int i=0; i<m; i++){
        int u = R[i][0], v = R[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=0; i<n; i++){
        nxt[i][0] = adj[i][0];
        if (adj[adj[i][0]][0] == i) nxt[i][0] += n;
        if (adj[i].size() == 1){
            nxt[i+n][0] = adj[i][0];
            if (adj[adj[i][0]][0] == i) nxt[i+n][0] += n;
        }
        else{
            nxt[i+n][0] = adj[i][1];
            if (adj[adj[i][1]][0] == i) nxt[i+n][0] += n;
        }
        // cout << i << " -> " << nxt[i][0] << '\n';
        // cout << i+n << " -> " << nxt[i+n][0] << '\n';
    }

    for (int j=1; j<30; j++)
        for (int i=0; i<2*n; i++)
            nxt[i][j] = nxt[nxt[i][j-1]][j-1];

    for (int i=0; i<q; i++){
        int ans = 0;
        for (int j=0; j<n; j++){
            int u = j, k = G[i];
            for (int b=0; b<30; b++)
                if (k>>b&1) u = nxt[u][b];
            if (u >= n) u -= n;
            ans += u == p;
        }
        answer(ans);
    }
}
