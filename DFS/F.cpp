#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+4;

int n,m,k;
vector<int> gov;
vector<int> adj[N];
bool vis[N];

void dfs(int u,int &cnt){
    vis[u] = true;
    cnt++;
    
    for (int v : adj[u])
        if (!vis[v])
            dfs(v, cnt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    gov.resize(k);
    
    for (int i=0; i<k; i++)
        cin >> gov[i];
        
    for (int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int ans = 0;
    int mx = 0;
    
    for (int g : gov){
        int cnt = 0;
        dfs(g, cnt);
        ans += cnt*(cnt-1)/2;
        mx = max(mx, cnt);
    }
    
    int cnt = 0;
    for (int i=1; i<=n; i++)
        cnt += !vis[i];
        
    ans += mx * cnt;
    ans += cnt*(cnt-1)/2;
    
    cout << ans - m << "\n";
        
    return 0;
}