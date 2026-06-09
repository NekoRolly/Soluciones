/*
Complejidad: O(n*m)
Memoria: O(n)
Puntaje: 21 + 0 + 0 = 21
Idea: Actualizar eficientemente en cada update
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1004;

int n,m;
bool edge[N];
int L[N],R[N];
int ans[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=1; i<=n; i++)
        L[i] = R[i] = i;

    for (int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        if (edge[u]){
            edge[u] = false;
            continue;
        }
        edge[u] = true;
        int l=u,r=v;
        while (l>1 && edge[l-1]) l--;
        while (r<n && edge[r]) r++;
        for (int i=1; i<=n; i++){
            if (L[i] == v) L[i] = l;
            if (R[i] == u) R[i] = r;
        }
    }

    for (int i=1; i<=n; i++)
        ans[L[i]]++, ans[R[i]+1]--;

    for (int i=1; i<=n; i++){
        ans[i] += ans[i-1];
        cout << ans[i] << '\n';
    }

    return 0;
}
