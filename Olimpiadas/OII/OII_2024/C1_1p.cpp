/*
Complejidad: O(n + q*n)
Memoria: O(n)
Puntaje: 1 + 0 + 0 + 0 + 0 + 0 = 1
Idea: Query en O(n)
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100004;

int n,X,q;
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> X;

    for (int i=1; i<=n; i++) cin >> a[i];

    cin >> q;

    while (q--){
        int l,r; cin >> l >> r;
        int mx = 0;
        if (l%2 == r%2) mx = a[r--];
        for (int i=0; l+i<r-i; i++)
            mx = max(mx, a[l+i] + a[r-i]);
        cout << (mx <= X);
    }
    cout << '\n';

    return 0;
}
