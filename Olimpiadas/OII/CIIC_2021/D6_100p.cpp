/*
Complejidad: O(n + k*logk*logn)
Memoria: O(n + k*logk*logn)
Puntaje: 10 + 10 + 10 + 10 + 20 + 40 = 100
Idea: DFS y usar small to large para el merge
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100004;

int n;
string s;
set<int> st[N];
int L[N],R[N];

void dfs(int u){
    if (s[u] == 'E') return;
    if (s[u] == 'L'){
        dfs(L[u]); swap(st[u], st[L[u]]);
        return;
    }
    dfs(L[u]), dfs(R[u]);
    if (st[L[u]].size() > st[R[u]].size()) swap(L[u], R[u]); // L -> R
    if (s[u] == 'A'){
        for (int x : st[L[u]])
            if (st[R[u]].find(x) != st[R[u]].end())
                st[u].insert(x);
    }
    if (s[u] == 'O'){
        for (int x : st[L[u]]) st[R[u]].insert(x);
        swap(st[u], st[R[u]]);
    }
    if (s[u] == 'X'){
        for (int x : st[L[u]]){
            if (st[R[u]].find(x) != st[R[u]].end())
                st[R[u]].erase(x);
            else st[R[u]].insert(x);
        }
        swap(st[u], st[R[u]]);
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
                st[i].insert(x);
            }
        }
        else if (s[i] == 'L') cin >> L[i];
        else cin >> L[i] >> R[i];
    }

    for (int i=0; i<n; i++){
        if (s[i] == 'L'){ dfs(i);
            for (int x : st[i]) cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}
