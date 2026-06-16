/*
Complejidad: O(nlogn + q)
Memoria: O(n)
Puntaje: 1 + 2 + 4 + 8 + 35 + 50 = 100
Idea: Precálculo con divide and conquer y óptimos
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100004;

int n,X,q;
int a[N];
int mx[N];

void divide(int l,int r,int mxL,int mxR){
    if (l >= r) return;
    int m = (l+r)>>1;
    int &mxM = mx[m]; mxM = mxR;
    while (mxM < mxL && m-mxM-1 >= 1 && m+mxM+2 <= n && a[m-mxM-1] + a[m+mxM+2] <= X) mxM++;
    divide(l, m, mxL, mxM);
    divide(m+1, r, m-mxM-1 > 1 ? mxM : N, mxR);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> X;

    for (int i=1; i<=n; i++) cin >> a[i];

    divide(1, n, N, -1);

    cin >> q;

    while (q--){
        int l,r,i; cin >> l >> r;
        int ans = 1, sz = r-l+1;
        if (sz%2 == 1 && a[r] > X) ans = 0;
        sz >>= 1;
        if (sz >= 1 && mx[l+sz-1] < sz-1) ans = 0;
        cout << ans;
    }
    cout << '\n';

    return 0;
}
