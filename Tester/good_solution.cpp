// Juguemos a las atrapadas hasta que la muerte nos separe
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int N = 2e5+4;
const ll infll = 1e18+4;
const int inf = 1e9;
const int mod = 1e9+7;

int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int n;
int a[N];
vector<int> adj[N];

int dfs(int u,int p,int g){
    int val;
    for (int x : arr)
        if (g%x != 0){
            val = x;
            break;
        }

    for (int v : adj[u])
        if (v != p)
            val += dfs(v, u, gcd(g, a[v]));

    return val;
}

void solve(){
    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> a[i];
        adj[i].clear();
    }

    for (int i=1; i<n; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i=1; i<=n; i++)
        cout << dfs(i, -1, a[i]) << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int kou = 1;
    cin >> kou;

    while (kou--)
        solve();

    return 0;
}