#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+4;
const int inf = 1e9+4;

int n;
vector<int> adj[N];
int dp[N][2];


void dfs(int u){
    int min_dif = inf;
    for (int v : adj[u]){
        dfs(v);
        dp[u][1] += min(dp[v][0], dp[v][1]);
        min_dif = min(min_dif, dp[v][1] - dp[v][0]);
    }
    dp[u][0] = dp[u][1] + min_dif;
    dp[u][1]++;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i=2; i<=n; i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    dfs(1);

    cout << min(dp[1][0], dp[1][1]) << "\n";

    return 0;
}