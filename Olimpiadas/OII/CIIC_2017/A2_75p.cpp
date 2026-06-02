/*
Complejidad: O(D)
Memoria: O(D)
Puntaje: 25 + 25 + 25 + 0 = 75
Idea: DP con transición O(1)
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1000004;
const int mod = 1000000;

int d,k;
int dp[N],pr[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> d;

    pr[0] = dp[0] = 1;
    for (int i=1; i<=d; i++){
        dp[i] = pr[i-1];
        if (i-k-1 >= 0) dp[i] = (dp[i] - pr[i-k-1] + mod) % mod;
        pr[i] = (pr[i-1] + dp[i]) % mod;
    }

    cout << dp[d] << '\n';

    return 0;
}
