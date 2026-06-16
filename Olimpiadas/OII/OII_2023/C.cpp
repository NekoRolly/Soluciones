#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    vector<int> last(n, -1);

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++){
            cin >> a[i][j];
            if (a[i][j] != 0) last[i] = j;
        }

    vector<ll> acum(n, 0);
    vector<bool> vis(n+1);

    for (int j=0; j<m; j++){
        fill(vis.begin(), vis.end(), false);
        for (int i=0; i<n; i++){
            if (last[i] > j || a[i][j] == 0) continue;
            ll A = abs(acum[i]), B = abs(a[i][j]);
            if (A % B != 0) continue;
            ll x = - A / B;
            if (acum[i] * a[i][j] < 0) x = -x;
            if (0 <= x && x <= n) vis[x] = true;
        }
        ll mex = 0;
        while (vis[mex]) mex++;
        cout << mex << ' ';
        for (int i=0; i<n; i++)
            acum[i] += mex * a[i][j];
    }
    cout << '\n';

    return 0;
}
