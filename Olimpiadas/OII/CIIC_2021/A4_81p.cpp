/*
Complejidad: O(n * fib(n) * n)
Memoria: O(fib(n))
Puntaje: 10 + 20 + 30 + 21 + 0 = 81
Idea: DP bitmask optimizado con reducción de estados
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 34;

int n,ans;
int a[N][N];
map<int,int> dp;

int Dp(int mask){
    if (mask == 0) return 0;
    if (dp.find(mask) != dp.end()) return dp[mask];
    int k = 31 - __builtin_clz(mask), x = 0;
    for (int i=0; i<k; i++) if (mask>>i&1)
        x = max(x, Dp(mask^(1<<i)^(1<<k)) + a[i][k]);
    return dp[mask] = x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];

    cout << Dp((1<<n)-1) << '\n';

    return 0;
}
