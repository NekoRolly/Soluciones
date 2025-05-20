#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int s(int x){
    int ans=0;
    while (x > 0){
        ans += x%10;
        x /= 10;
    }
    return ans;
}

ll f(int x){
    return 1ll*x*x - x*s(x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,ans=0;
    cin >> n >> m;

    for (int i=1; i<=n; i++)
        ans += (f(i) >= m);

    cout << ans << "\n";

    return 0;
}