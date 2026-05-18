#include "ricehub.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 2e5+4;
const int inf = 1e9+4;

int besthub(int R, int L, int X[], long long B){
    ll ans = 1, n = R;
    for (int i=0; i<n; i++){
        ll acum = 0, cnt = 1;
        for (int j=1; ; j++){
            if (i+j == n) break;
            acum += X[i+j] - X[i], cnt++;
            if (acum > B) break;
            ans = max(ans, cnt);

            if (i-j == -1) break;
            acum += X[i] - X[i-j], cnt++;
            if (acum > B) break;
            ans = max(ans, cnt);
        }
    }
    return ans;
}
