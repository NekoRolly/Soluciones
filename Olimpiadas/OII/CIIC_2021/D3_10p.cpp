/*
Complejidad: O(n + klogk)
Memoria: O(n + k)
Puntaje: 0 + 10 + 0 + 0 + 0 + 0 = 10
Idea: DFS y guardar vector de tiempos
Nota: Caso especial sin OR ni XOR
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100004;
const int M = 5004;

int n;
string s;
vector<int> vec[N];
int L[N],R[N];

void dfs(int u){
    if (s[u] == 'E') return;
    if (s[u] == 'L'){
        dfs(L[u]); vec[u] = vec[L[u]];
        return;
    }
    dfs(L[u]), dfs(R[u]);
    for (int i=0,j=0; i<vec[L[u]].size() && j<vec[R[u]].size(); ){
        if (vec[L[u]][i] < vec[R[u]][j]) i++;
        else if (vec[L[u]][i] > vec[R[u]][j]) j++;
        else{ vec[u].push_back(vec[L[u]][i]); i++, j++;}
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;

    for (int i=0; i<n; i++){
        int m; cin >> m;
        if (s[i] == 'E'){
            vec[i].resize(m);
            for (int &x : vec[i]) cin >> x;
            sort(vec[i].begin(), vec[i].end());
        }
        else if (s[i] == 'L') cin >> L[i];
        else cin >> L[i] >> R[i];
    }

    for (int i=0; i<n; i++){
        if (s[i] == 'L'){ dfs(i);
            for (int x : vec[i])
                cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}
