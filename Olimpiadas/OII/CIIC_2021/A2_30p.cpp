/*
Complejidad: O(n^2 * 2^n)
Memoria: O(2^n)
Puntaje: 10 + 20 + 0 + 0 + 0 = 30
Idea: DP bitmask
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 34;

int n,ans;
int a[N][N];
int dp[1<<22];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];

    for (int mask=0; mask<(1<<n); mask++){
        for (int i=0; i<n; i++) if (mask>>i&1)
            for (int j=i+1; j<n; j++) if (mask>>j&1)
                dp[mask] = max(dp[mask], dp[mask^(1<<i)^(1<<j)] + a[i][j]);
    }

    cout << dp[(1<<n)-1] << '\n';

    return 0;
}
