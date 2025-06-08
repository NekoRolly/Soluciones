#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf = 1e9 + 4;
const ll infll = 1e18 + 4;
const int mod = 1e9 + 7;
const int N = 1e6 + 4;

bool is_good(int x,int a,int b){
    while (x > 0){
        if (x%10 != a && x%10 != b)
            return false;
        x /= 10;
    }
    return true;
}

int P(int a,int b){
    return 1ll*a*b%mod;
}

int S(int a,int b){
    return (a+b)%mod;
}

int BP(int a,int b){
    int ans = 1;
    for (; b>>=1; a=P(a, a))
        if (b&1)
            ans = P(ans, a);
    return ans;
}

int fac[N],Ifac[N];

int C(int n,int k){
    return P(fac[n], P(Ifac[k], Ifac[n-k]));
}

void solve(){
    int a,b,n;
    cin >> a >> b >> n;

    fac[0] = 1;
    for (int i=1; i<=n; i++)
        fac[i] = P(fac[i-1], i);
    Ifac[n] = BP(fac[n], mod-2);
    for (int i=n-1; i>=0; i--)
        Ifac[i] = P(Ifac[i+1], i+1);
    
    int ans = 0;
    for (int i=0; i<=n; i++){
        int sum = a*i + b*(n-i);
        if (is_good(sum, a, b))
            ans = S(ans, C(n, i));
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int kou = 1;
    // cin >> kou;

    while (kou--)
        solve();

    return 0;
}