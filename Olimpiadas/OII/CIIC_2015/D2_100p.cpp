// Complejidad  : O(n*logn)
// Memoria      : O(n*logn)
// Puntaje      : 40 + 60 = 100
// Idea         : Binary Lifting
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 1e5+4;
const int inf = 1e9+4;

int n;
int pa[N][18];
bool ciclo[N];
vector<int> vec[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=1; i<=n; i++) cin >> pa[i][0];

    for (int j=1; j<18; j++)
        for (int i=1; i<=n; i++)
            pa[i][j] = pa[pa[i][j-1]][j-1];

    for (int i=1; i<=n; i++){
        vec[pa[i][17]].push_back(i);
        ciclo[pa[i][17]] = true;
    }

    int T = inf,K = 0,M;
    for (int i=1; i<=n; i++){
        if (!ciclo[i]) continue;
        int val = vec[i].size(), mx_len = -1, id = -1;
        for (int u : vec[i]){
            int len = 0, aux = u;
            for (int j=16; j>=0; j--)
                if (!ciclo[pa[aux][j]]) len += 1<<j, aux = pa[aux][j];
            if (!ciclo[aux]) len++, aux = pa[aux][0];
            if (mx_len < len) mx_len = len, id = aux;
        }
        if (K < val) K = val, T = mx_len, M = id;
        else if (K == val && T > mx_len) T = mx_len, M = id;
        else if (K == val && T == mx_len && M > id) M = id;
    }

    cout << T*5 << ' ' << K*10 << ' ' << M << '\n';

    return 0;
}
