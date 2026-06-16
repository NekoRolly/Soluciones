/*
Complejidad: O(n^2 + q)
Memoria: O(n)
Puntaje: 0 + 2 + 0 + 0 + 0 + 0 = 2
Idea: Precálculo para responder query en O(1)
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100004;

int n,X,q;
int a[N];
int mx[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> X;

    for (int i=1; i<=n; i++) cin >> a[i];

    for (int i=1; i<n; i++){
        int &j = mx[i]; j = -1;
        while (i-j-1 >= 1 && i+j+2 <= n && a[i-j-1] + a[i+j+2] <= X) j++;
    }

    cin >> q;

    while (q--){
        int l,r,i; cin >> l >> r;
        int ans = 1, sz = r-l+1;
        if (sz%2 == 1 && a[r] > X) ans = 0;
        sz >>= 1;
        if (mx[l+sz-1] < sz-1) ans = 0;
        cout << ans;
    }
    cout << '\n';

    return 0;
}
