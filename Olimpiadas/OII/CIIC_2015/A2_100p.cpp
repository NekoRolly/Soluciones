// Complejidad  : O(n)
// Memoria      : O(1)
// Puntaje      : 30 + 70 = 100
// Idea         : Ad Hoc
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+4;
const int inf = 1e9+4;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    ll acum = 0, ans = inf;

    for (int i=1; i<=n; i++){
        int x; cin >> x;
        acum += x;
        ans = min(ans, acum / i);
    }

    cout << ans << '\n';

    return 0;
}
