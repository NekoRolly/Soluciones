#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,ans=0,mx=0;
    cin >> n;

    int divi[n+1] = {0};

    for (int i=1; i<=n; i++)
        for (int j=i; j<=n; j+=i)
            divi[j]++;

    for (int i=1; i<=n; i++){
        if (divi[i] > mx){
            mx = divi[i];
            ans = i;
        }
    }

    cout << ans << "\n";

    return 0;
}