#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int N = 2e5+4;
const ll infll = 1e18+4;

int n,m;
vector<pair<int,int>> adj[N];
ll dis[N];
int up[N];

void dijkstra_pq(int s){
    for (int i=1; i<=n; i++)
        dis[i] = infll;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, s});
    dis[s] = 0;

    while (!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if (w > dis[u]) continue;

        for (auto [v, we] : adj[u]){
            if (dis[v] > dis[u] + we){
                dis[v] = dis[u] + we;
                up[v] = u;
                pq.push({dis[v], v});
            }
        }
    }
}

void dijkstra_pq_rev(int s){
    for (int i=1; i<=n; i++)
        dis[i] = infll;

    priority_queue<pll> pq;
    pq.push({-0, s});
    dis[s] = 0;

    while (!pq.empty()){
        auto [w, u] = pq.top();
        w = -w;
        pq.pop();

        if (w > dis[u]) continue;

        for (auto [v, we] : adj[u]){
            if (dis[v] > dis[u] + we){
                dis[v] = dis[u] + we;
                up[v] = u;
                pq.push({-dis[v], v});
            }
        }
    }
}

void dijkstra_st(int s){
    for (int i=1; i<=n; i++)
        dis[i] = infll;

    set<pll> st;
    st.insert({0, s});
    dis[s] = 0;

    while (!st.empty()){
        auto [w, u] = *st.begin();
        st.erase({w, u});

        if (w > dis[u]) continue;

        for (auto [v, we] : adj[u]){
            if (dis[v] > dis[u] + we){
                dis[v] = dis[u] + we;
                up[v] = u;
                st.insert({dis[v], v});
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
    }

    dijkstra_st(1);

    for (int i=1; i<=n; i++)
        cout << dis[i] << " ";
    cout << "\n";

    return 0;
}