#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int pr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
ll ans,mx;

void go(ll val,int i,int cnt,int max_e,ll max_val){
    if (i < 15){
        for (int e=0; e<=max_e; e++){
            go(val, i+1, cnt*(e+1), e, max_val);
            if (val > max_val/pr[i]) break;
            val *= pr[i];
        }
    }
    if (cnt > mx){
        mx = cnt;
        ans = val;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    go(1, 0, 1, 59, n);

    cout << ans << "\n";

    return 0;
}