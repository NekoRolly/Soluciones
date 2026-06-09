/*
Complejidad: O(sqrt(m) * 50000 / 64)
Memoria: O(sqrt(m) * 50000 / 64)
Puntaje: 0 + 16 + 0 + 0 + 0 = 16
Idea: DP knapsack con bitset
*/
#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9+4;
const int N = 1004;

int n,m;
int p[N],sum;
bitset<50001> dp[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i=1; i<=n; i++){
        cin >> p[i];
        sum += p[i];
    }

    dp[0][0] = 1;

    for (int i=1; i<=n; i++)
        dp[i] = dp[i-1] | (dp[i-1] << p[i]);

    int mx = 0;
    for (int i=0; i<=sum/2; i++)
        if (dp[n][i]) mx = i;

    cout << sum - 2*mx << '\n';

    for (int i=n; i>=1; i--){
        if (dp[i-1][mx]) continue;
        cout << i << ' ';
        mx -= p[i];
    }
    cout << '\n';

    return 0;
}
