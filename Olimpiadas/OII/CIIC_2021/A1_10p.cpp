/*
Complejidad: O(n!)
Memoria: O(n)
Puntaje: 10 + 0 + 0 + 0 + 0 = 10
Idea: Fuerza Bruta
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 34;

int n,ans;
int a[N][N],p[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i=0; i<n; i++){
        p[i] = i;
        for (int j=0; j<n; j++)
            cin >> a[i][j];
    }

    do{
        int val = 0;
        for (int i=0; i<n; i+=2) val += a[p[i]][p[i+1]];
        ans = max(ans, val);
    } while (next_permutation(p, p+n));

    cout << ans << '\n';

    return 0;
}
