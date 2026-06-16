/*
Complejidad: O((n + k)*input/64)
Memoria: O(n*input/64)
Puntaje: 10 + 0 + 0 + 0 + 20 + 0 = 30
Idea: DFS y guardar estado de cada tiempo con bitset
Nota: Caso especial con input <= 5000
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100004;
const int M = 5004;

int n;
string s;
bitset<M> t[N];
int L[N],R[N];

void dfs(int u){
    if (s[u] == 'E') return;
    if (s[u] == 'L'){
        dfs(L[u]); t[u] = t[L[u]];
        return;
    }
    dfs(L[u]), dfs(R[u]);
    if (s[u] == 'A') t[u] = t[L[u]] & t[R[u]];
    if (s[u] == 'O') t[u] = t[L[u]] | t[R[u]];
    if (s[u] == 'X') t[u] = t[L[u]] ^ t[R[u]];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;

    for (int i=0; i<n; i++){
        int m; cin >> m;
        if (s[i] == 'E'){
            for (int j=0; j<m; j++){
                int x; cin >> x;
                t[i][x] = 1;
            }
        }
        else if (s[i] == 'L') cin >> L[i];
        else cin >> L[i] >> R[i];
    }

    for (int i=0; i<n; i++){
        if (s[i] == 'L'){ dfs(i);
            for (int j=1; j<M; j++)
                if (t[i][j]) cout << j << ' ';
        }
        cout << '\n';
    }

    return 0;
}
