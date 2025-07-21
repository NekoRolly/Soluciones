#include<bits/stdc++.h>
#include"werewolf.h"
using namespace std;
typedef vector<int> vi;

const int N = 2e5+4;

int n;
vi adj[N];
bool vis1[N],vis2[N];

void dfs(int u,int l,int r,bool vis[]){
    if (u < l || r < u) return;
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v])
            dfs(v, l, r, vis);
}

vi check_validity(int N,vi X,vi Y,vi S,vi E,vi L,vi R){
    n = N;

    for (int i=0; i<X.size(); i++){
        adj[X[i]].push_back(Y[i]);
        adj[Y[i]].push_back(X[i]);
    }

    vector<int> vans;
    for (int j=0; j<S.size(); j++){
        for (int i=0; i<n; i++)
            vis1[i] = vis2[i] = false;

        dfs(S[j], L[j], n-1, vis1);
        dfs(E[j], 0, R[j], vis2);

        int ans = 0;
        for (int i=0; i<n; i++)
            if (vis1[i] && vis2[i])
                ans = 1;

        vans.push_back(ans);
    }

    return vans;
}