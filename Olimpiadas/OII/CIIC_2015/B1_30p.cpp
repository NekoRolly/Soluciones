// Complejidad  : O(n*m)
// Memoria      : O(n+m)
// Puntaje      : 30 + 0 + 0 = 30
// Idea         : Fuerza Bruta
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+4;

int n,m,L;
int x[N],p[N];
int ans[N],c[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> L >> m;

    for (int i=1; i<=n; i++) cin >> x[i] >> p[i];
    for (int i=1; i<=m; i++) cin >> c[i];

    int cnt = 0;
    for (int i=1; i<=m; i++){
        ans[i] = -1;
        for (int j=1; j<=n; j++)
            if (x[j] <= c[i] && c[i] <= x[j] + p[j]){
                if (ans[i] == -1 || x[ans[i]] < x[j]) ans[i] = j;
            }
        cnt += (ans[i] != -1);
    }

    cout << cnt << '\n';
    for (int i=1; i<=m; i++)
        cout << ans[i] << '\n';

    return 0;
}
