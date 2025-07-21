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

struct Dsu{
    int n,t[N],sz[N];

    void build(int m){
        n = m;
        for (int i=1; i<=n; i++)
            t[i] = i, sz[i] = 0;
    }

    int find(int x){
        return x == t[x] ? x : t[x] = find(t[x]);
    }

    void update(int x){
        sz[find(x)]++;
    }

    void join(int a,int b){
        a = find(a), b = find(b);
        if (a != b){
            t[a] = b;
            sz[b] += sz[a];
        }
    }

    int get(int x){
        return sz[find(x)];
    }
} dsu;

int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int prr[10]; 

int n;
int a[N];
int cnt[N][10];

struct edge{
    int u,v,w;
} ed[N];

bool vis[N];

void solve(){
    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> a[i];
        vis[i] = false;
    }

    dsu.build(n);

    for (int i=1; i<n; i++){
        auto &[u, v, w] = ed[i];
        cin >> u >> v;
        w = __gcd(a[u], a[v]);
    }

    for (int g=9; g>=0; g--){
        for (int i=1; i<=n; i++)
            if (!vis[i] && a[i]%prr[g] == 0){
                dsu.update(i);
                vis[i] = true;
            }

        for (int i=1; i<n; i++){
            auto &[u, v, w] = ed[i];
            if (w%prr[g] == 0)
                dsu.join(u, v);
        }

        for (int i=1; i<=n; i++){
            cnt[i][g] = n - dsu.get(i);
        }
    }

    for (int i=1; i<=n; i++){
        int ans = 0;
        for (int g=0; g<10; g++){
            int Cnt = (g == 9 ? n : cnt[i][g+1]) - cnt[i][g];
            // cout << i << " " << arr[g] << " : " << Cnt << "\n";
            ans += Cnt * arr[g];
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    prr[0] = 1;
    for (int i=1; i<10; i++)
        prr[i] = prr[i-1] * arr[i-1];

    // cout << prr[9] << "\n";

    int kou = 1;
    cin >> kou;

    while (kou--)
        solve();

    return 0;
}