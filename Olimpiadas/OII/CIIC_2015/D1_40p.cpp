/*
Complejidad: O(n^2)
Memoria: O(n)
Puntaje: 40 + 0 = 40
Idea: Simulación
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 1e5+4;
const int inf = 1e9+4;

int n;
int nxt[N],a[N],b[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int T = 0, K = 1, M = 1;

    for (int i=1; i<=n; i++){
        cin >> nxt[i]; a[i] = 1;
    }

    for (int t=1; t<=n; t++){
        for (int i=1; i<=n; i++) b[nxt[i]] += a[i];
        for (int i=1; i<=n; i++){
            a[i] = b[i], b[i] = 0;
            if (a[i] > K) T = t, K = a[i], M = i;
        }
    }

    cout << T*5 << ' ' << K*10 << ' ' << M << '\n';

    return 0;
}
