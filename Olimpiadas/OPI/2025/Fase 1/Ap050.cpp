#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int s(ll x){
    int ans=0;
    while (x > 0){
        ans += x%10;
        x /= 10;
    }
    return ans;
}

ll f(ll x){
    return 1ll*x*x - x*s(x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;

    int pos = 1;
    while (pos <= n && f(pos) < m) pos++;

    cout << n - pos + 1 << "\n";

    return 0;
}