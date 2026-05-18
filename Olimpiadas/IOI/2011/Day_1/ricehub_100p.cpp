#include "ricehub.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 2e5+4;
const int inf = 1e9+4;

ll b;
int a[N];
ll pr[N];
int ans,n;

ll sum(int l,int r){
    return pr[r+1] - pr[l];
}

ll cost(int l,int r,int i,ll x){
    if (l < 0 || r >= n) return b+1;
    ll L = x * (i-l) - sum(l, i-1);
    ll R = sum(i+1, r) - x * (r-i);
    return L + R;
}

int besthub(int R, int L, int X[], long long B){
    ans = 1, n = R, b = B;

    for (int i=1; i<=n; i++){
        a[i] = X[i-1];
        pr[i] = pr[i-1] + a[i];
    }

    for (int i=0; i<n; i++){
        ll acum = 0;
        int l = 0, r = n;
        while (l+1<r){
            int m = (l+r)>>1;
            if (cost(i-m, i+m, i, X[i]) <= B) l = m;
            else r = m;
        }
        acum = cost(i-l, i+l, i, X[i]);
        int len = 2*l + 1;
        // cout << i << " : " << acum << ' ' << len << '\n';
        if (i+l+1 < n && acum + X[i+l+1] - X[i] <= B)
            acum += X[i+l+1] - X[i], len++;
        ans = max(ans, len);
    }
    return ans;
}
