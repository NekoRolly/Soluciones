#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+4;
const int mod = 998244353;

int P(int a,int b){ return 1ll*a*b%mod;}
int S(int a,int b){ return (a+b)%mod;}
int BP(int a,int b){ int ans = 1;
    for (; b>0; b>>=1, a=P(a, a))
        if (b&1) ans = P(ans, a);
    return ans;
}

int n,k;
int fac[N],Ifac[N];
int dp[N],acum;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    fac[0] = 1;
    for (int i=1; i<=n; i++) fac[i] = P(fac[i-1], i);
    Ifac[n] = BP(fac[n], mod-2);
    for (int i=n-1; i>=0; i--) Ifac[i] = P(Ifac[i+1], i+1);

    dp[0] = 1;
    for (int i=k; i<=n; i++){
        acum = S(acum, P(dp[i-k], Ifac[i-k]));
        dp[i] = P(fac[i-1], acum);
    }

    cout << dp[n] << '\n';

    return 0;
}
