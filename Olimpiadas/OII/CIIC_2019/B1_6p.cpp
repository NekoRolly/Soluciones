/*
Complejidad: O(n^2 * 2^n)
Memoria: O(n^2)
Puntaje: 0 + 0 + 6 + 0 + 0 = 6
Idea: Fuerza Bruta con Bitmask
*/
#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9+4;

int n,m;
int p[24];
int odio[24][24];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=0; i<n; i++) cin >> p[i];

    for (int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        odio[u-1][v-1] = odio[v-1][u-1] = true;
    }

    int ans = inf, mask_ans;
    for (int mask=1; mask<(1<<n); mask++){
        vector<int> vec1,vec2;
        for (int i=0; i<n; i++){
            if (mask>>i&1) vec1.push_back(i);
            else vec2.push_back(i);
        }
        bool flag = true;
        for (int u : vec1){
            for (int v : vec2)
                if (!odio[u][v]){
                    flag = false;
                    break;
                }
            if (!flag) break;
        }
        if (!flag) continue;
        int sum = 0;
        for (int u : vec1) sum += p[u];
        for (int v : vec2) sum -= p[v];
        if (sum < 0) sum = -sum;
        if (ans > sum) ans = sum, mask_ans = mask;
    }

    cout << ans << '\n';

    for (int i=0; i<n; i++)
        if (mask_ans>>i&1) cout << i+1 << ' ';
    cout << '\n';

    return 0;
}
