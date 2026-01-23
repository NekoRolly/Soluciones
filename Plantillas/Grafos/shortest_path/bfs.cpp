#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9+4;
const int N = 1e5+4;

int n,m;
vector<int> adj[N];
int dis[N];
int up[N];

void bfs(int s){
    for (int i=1; i<=n; i++)
        dis[i] = inf;
    dis[s] = 0;
    up[s] = -1;
    
    queue<int> qu;
    qu.push(s);

    while (!qu.empty()){
        int u = qu.front();
        qu.pop();
        for (int v : adj[u])
            if (dis[v] == inf){
                dis[v] = dis[u] + 1;
                up[v] = u;
                qu.push(v);
            }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);

    if (dis[n] == inf){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << dis[n]+1 << "\n";
        int x = n;
        vector<int> vec;
        while (x != -1){
            vec.push_back(x);
            x = up[x];
        }

        reverse(vec.begin(), vec.end());
        for (int x : vec)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}