// Complejidad  : O(n*logn + m + L)
// Memoria      : O(n + m + L)
// Puntaje      : 30 + 40 + 0 = 70
// Idea         : Simulación
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 1e5+4;
const int M = 1e6+4;

int n,m,L;
vector<pii> rs[M];
vector<int> ls[M],cs[M];
int ans[N];
set<pii> st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> L >> m;

    for (int i=1; i<=n; i++){
        int x,p; cin >> x >> p;
        ls[x].push_back(i);
        rs[x+p].push_back({x, i});
    }
    for (int i=1; i<=m; i++){
        int c; cin >> c;
        cs[c].push_back(i);
    }

    int cnt = 0;
    for (int x=0; x<=L; x++){
        for (int id : ls[x]) st.insert({x, id});
        for (int id : cs[x]){
            if (st.empty()) ans[id] = -1;
            else ans[id] = st.rbegin()->second, cnt++;
        }
        for (pii par : rs[x]) st.erase(par);
    }

    cout << cnt << '\n';
    for (int i=1; i<=m; i++)
        cout << ans[i] << '\n';

    return 0;
}
