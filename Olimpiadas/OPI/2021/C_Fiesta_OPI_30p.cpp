#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> a;

    int ans = 0;
    for (int i=1; i<=a; i++)
        ans += (i%n != 0 && i%m != 0);

    cout << ans << "\n";

    return 0;
}