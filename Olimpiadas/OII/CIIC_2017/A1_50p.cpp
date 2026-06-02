/*
Complejidad: O(D*min(D, k))
Memoria: O(D)
Puntaje: 25 + 25 + 0 + 0 = 50
Idea: DP con transición O(min(D, k))
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1000004;
const int mod = 1000000;

int d,k;
int dp[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> d;

    dp[0] = 1;
    for (int i=1; i<=d; i++)
        for (int j=max(0, i-k); j<i; j++)
            dp[i] = (dp[i] + dp[j]) % mod;

    cout << dp[d] << '\n';

    return 0;
}
