#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+4;

int n,m;
int vis[N];
int td[N],tf[N];
vector<int> adj[N];
vector<int> toposort;
int col[N];
bool ciclo;

void dfs(int u,int p){
    vis[u] = 1;
    td[u] = cur++;

    for (int v : adj[u]){
        if (vis[v] == 0)
            dfs(v, u);
        else if (v != p && vis[v] == 1)
            ciclo = true;
    }

    vis[u] = 2;
    tf[u] = cur++;
    toposort.push_back(u);
}

bool es_bipartito;

void dfs_bip(int u){
    for (int v : adj[u]){
        if (col[v] == 0){
            col[v] = 3 - col[u];
            dfs_bip(v);
        }
        else if (col[v] == col[u])
            es_bipartito = false;
    }
}

bool is_ancestor(int a,int b){
    return td[a] <= td[b] && tf[b] <= tf[a];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    es_bipartito = true;
    col[1] = 1;
    dfs_bip(1);

    return 0;
}