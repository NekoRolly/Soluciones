// Complejidad  : O(n*maxC)
// Memoria      : O(n)
// Puntaje      : 30 + 0 = 30
// Idea         : Fuerza Bruta y Simulación
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+4;
const int inf = 1e9+4;

int n;
int a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    ll acum, ans = 0;

    while (true){
        bool flag = true; acum = 0;
        for (int i=1; i<=n; i++){
            acum += a[i] - (ans+1);
            if (acum < 0) flag = false;
        }
        if (!flag) break;
        ans++;
    }

    cout << ans << '\n';

    return 0;
}
