#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> a;

    cout << a - a/n - a/m + a/(n*m) << "\n";

    return 0;
}