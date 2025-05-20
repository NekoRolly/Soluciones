#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,ans=0,mx=0;
    cin >> n;

    for (int i=1; i<=n; i++){
        int cnt = 0;
        for (int j=1; j*j<=i; j++)
            cnt += (i%j == 0)*(j*j == i ? 1 : 2);
        if (mx < cnt){
            mx = cnt;
            ans = i;
        }
    }

    cout << ans << "\n";

    return 0;
}