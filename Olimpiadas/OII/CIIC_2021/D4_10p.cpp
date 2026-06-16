/*
Complejidad: O(n + klogk)
Memoria: O(n + k)
Puntaje: 0 + 0 + 10 + 0 + 0 + 0 = 10
Idea: DFS y guardar vector de tiempos
Nota: Caso especial sin AND ni XOR
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100004;

int n;
string s;
vector<int> vec[N];
int L[N],R[N];

void dfs(int u,int rt){
    if (s[u] == 'E'){
        for (int x : vec[u]) vec[rt].push_back(x);
        return;
    }
    dfs(L[u], rt);
    if (s[u] != 'L') dfs(R[u], rt);
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
        if (s[i] == 'L'){ dfs(i, i);
            sort(vec[i].begin(), vec[i].end());
            vec[i].erase(unique(vec[i].begin(), vec[i].end()), vec[i].end());
            for (int x : vec[i])
                cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}
