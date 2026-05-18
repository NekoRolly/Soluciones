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

void count_routes(int _n, int _m, int _p, int R[][2], int q, int G[]){
    n = _n, m = _m, p = _p;

    for (int i=0; i<m; i++){
        int u = R[i][0], v = R[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=0; i<q; i++){
        int ans = 0;
        for (int j=0; j<n; j++){
            int u = j, pa = -1, k = G[i];
            //cout << "adj: ";
            //for (int x : adj[u])
            //    cout << x << ' ';
            // cout << '\n';
            while (k--){
                if (adj[u].size() == 1 || adj[u][0] != pa){
                    pa = u;
                    u = adj[u][0];
                }
                else{
                    pa = u;
                    u = adj[u][1];
                }
            }

            ans += u == p;
        }
        answer(ans);
    }
}
