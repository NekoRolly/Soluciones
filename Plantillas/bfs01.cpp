#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+4;

int n,m;
vector<pair<int,int>> adj[N];
bool vis[N];
int dis[N];

void bfs01(int rt){
    for (int i=1; i<=n; i++){
        dis[i] = -1;
        vis[i] = false;
    }

    deque<int> dq;
    dq.push_front(rt);
    dis[rt] = 0;

    while (!dq.empty()){
        int u = dq.front();
        dq.pop_front();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto [v, we] : adj[u]){
            if (dis[v] == -1 || dis[v] > dis[u] + we){
                dis[v] = dis[u] + we;
                if (we == 0)
                    dq.push_front(v);
                else
                    dq.push_back(v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while (m--){
        int a,b,we;
        cin >> a >> b >> we;

        adj[a].push_back({b, we});
        adj[b].push_back({a, we});
    }

    bfs01(1);

    for (int i=1; i<=n; i++)
        cout << dis[i] << " ";
    cout << "\n";

    return 0;
}