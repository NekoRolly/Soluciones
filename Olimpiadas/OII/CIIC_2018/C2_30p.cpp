/*
Complejidad: O(n)
Memoria: O(n)
Puntaje: 10 + 0 + 0 + 0 + 20 + 0 = 30
Idea: Two Pointers o Binary Search en el árbol especial
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500004;

int n,P,k;
ll ans;
int a[N];
vector<int> adj[N],vec;

void dfs(int u,int p){
    vec.push_back(a[u]);
    for (int v : adj[u])
        if (v != p) dfs(v, u);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> P >> k; k--;

    for (int i=1; i<=n; i++){
        int x; cin >> x;
        a[i] = x < P;
    }

    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int rt = -1;
    for (int i=1; i<=n; i++)
        if (adj[i].size() == 1) rt = i;
    assert(rt != -1);

    dfs(rt, -1);

    int r1=0,r2=0,sum1=0,sum2=0;
    for (int i=0; i<n; i++){
        r1 = max(r1, i), r2 = max(r2, i);
        while (r1 < n && sum1 + vec[r1] < k) sum1 += vec[r1++];
        while (r2 < n && sum2 + vec[r2] <= k) sum2 += vec[r2++];
        ans += r2 - r1;
        if (r1 > i) sum1 -= vec[i];
        if (r2 > i) sum2 -= vec[i];
    }

    cout << ans << '\n';

    return 0;
}
