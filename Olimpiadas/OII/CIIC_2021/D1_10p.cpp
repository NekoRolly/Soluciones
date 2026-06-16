/*
Complejidad: O((n + k)*input)
Memoria: O(n*input)
Puntaje: 10 + 0 + 0 + 0 + 0 + 0 = 10
Idea: DFS y guardar estado de cada tiempo
Nota: Caso especial con input <= 5000
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 504;
const int M = 5004;

int n;
string s;
bool t[N][M];
int L[N],R[N];

void dfs(int u){
    if (s[u] == 'E') return;
    if (s[u] == 'L'){ dfs(L[u]);
        for (int i=1; i<M; i++)
            t[u][i] = t[L[u]][i];
        return;
    }
    dfs(L[u]), dfs(R[u]);
    for (int i=1; i<M; i++){
        if (s[u] == 'A') t[u][i] = t[L[u]][i] & t[R[u]][i];
        if (s[u] == 'O') t[u][i] = t[L[u]][i] | t[R[u]][i];
        if (s[u] == 'X') t[u][i] = t[L[u]][i] ^ t[R[u]][i];
    }
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
                t[i][x] = true;
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
