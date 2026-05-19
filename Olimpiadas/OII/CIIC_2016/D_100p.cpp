#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 1e5+4;
const int M = 2e5+4;
const int K = 1e6+4;

struct Node{
    ll sum,cnt;

    void operator+=(Node o){
        sum += o.sum, cnt += o.cnt;
    }

    Node operator-(Node o){
        return {sum - o.sum, cnt - o.cnt};
    }
};

struct Fenwick_Tree{
    int n;
    Node t[K];

    void update(int i,Node val){
        for (; i<=n; i+=i&-i) t[i] += val;
    }

    Node prefix(int i){
        Node ans = {0, 0};
        for (; i>0; i-=i&-i) ans += t[i];
        return ans;
    }

    Node query(int l,int r){
        return prefix(r) - prefix(l-1);
    }
} fwt;

int n,m,q;
int mp[N];
vector<int> adj[N];
vector<pii> Qs[N];
int val[M],freq[M];
ll ans[M];

void dfs(int u){
    int mi = mp[u];
    if (u != 1){
        freq[mi]++;
        if (freq[mi] == 1) fwt.update(val[mi], {val[mi], 1});
    }
    for (auto [k, id] : Qs[u]){
        Node x = fwt.query(k+1, fwt.n);
        ans[id] = x.sum - x.cnt*k;
    }
    for (int v : adj[u]) dfs(v);
    if (u != 1){
        freq[mi]--;
        if (freq[mi] == 0) fwt.update(val[mi], {-val[mi], -1});
    }
}
/*
Complejidad: O(m+k+(n+q)*logk)
Memoria: O(n+m+q+k)
Puntaje: 20 + 20 + 60 = 100
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    for (int i=1; i<=m; i++)
        cin >> val[i];

    for (int i=2; i<=n; i++){
        int p; cin >> p >> mp[i];
        adj[p].push_back(i);
    }

    for (int i=0; i<q; i++){
        int u,k; cin >> u >> k;
        Qs[u].push_back({k, i});
    }

    fwt.n = 1000000;
    dfs(1);

    for (int i=0; i<q; i++)
        cout << ans[i] << '\n';

    return 0;
}
