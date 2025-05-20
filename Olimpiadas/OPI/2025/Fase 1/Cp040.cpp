#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,ans=0,mx=0;
    cin >> n;

    int divi[n+1];
    int lp[n+1] = {0};
    int pe[n+1];
    int e[n+1];

    for (int i=2; i<=n; i++)
        if (lp[i] == 0)
            for (int j=i; j<=n; j+=i)
                lp[j] = i;

    divi[1] = pe[1] = 1;
    for (int i=2; i<=n; i++){
        int p = lp[i];
        e[i] = (lp[i/p] == p ? e[i/p]+1 : 1);
        pe[i] = (lp[i/p] == p ? pe[i/p]*p : p);
        divi[i] = (i == pe[i] ? e[i]+1 : divi[pe[i]] * divi[i/pe[i]]);
    }

    for (int i=1; i<=n; i++){
        if (divi[i] > mx){
            mx = divi[i];
            ans = i;
        }
    }

    cout << ans << "\n";

    return 0;
}