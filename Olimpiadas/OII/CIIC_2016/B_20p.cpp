#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+4;

int n,m;
int l[N],r[N];
int cnt[N];
int dp[1<<10];
bool valid[1<<10];

bool check(int mask){
    fill(cnt+1, cnt+n+1, 0);
    for (int i=0; i<m; i++)
        if (mask>>i&1){
            if (l[i] <= r[i])
                for (int j=l[i]; j<=r[i]; j++) cnt[j]++;
            else{
                for (int j=1; j<=r[i]; j++) cnt[j]++;
                for (int j=l[i]; j<=n; j++) cnt[j]++;
            }
        }
    for (int i=1; i<=n; i++)
        if (cnt[i] > 1) return false;
    return true;
}
/*
Complejidad: O(n*m*2^m + 4^m)
Memoria: O(n+2^m)
Puntaje: 20 + 0 + 0 = 20
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=0; i<m; i++)
        cin >> l[i] >> r[i];

    for (int mask=1; mask<(1<<m); mask++)
        valid[mask] = check(mask);

    fill(dp+1, dp+(1<<m), m);
    for (int mask=1; mask<(1<<m); mask++)
        for (int sm=1; sm<=mask; sm++)
            if ((mask&sm) == sm && valid[sm])
                dp[mask] = min(dp[mask], dp[mask^sm] + 1);

    cout << dp[(1<<m)-1] << '\n';

    return 0;
}
