#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 54;
const int M = 104;
const int inf = 1e9+4;

int n;
int lle[N],fe[N];
int dp[N][M][M];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> lle[i] >> fe[i];
    }

    memset(dp, -inf, sizeof dp);
    dp[0][0][0] = 0;

    for (int i=1; i<=n; i++)
        for (int L=0; L<=100; L++)
            for (int F=0; F<=100; F++){
                dp[i][L][F] = max(dp[i][L][F], dp[i-1][L][F]);
                if (L+lle[i] <= 100){
                    int &x = dp[i][L+lle[i]][min(100, F+fe[i])];
                    x = max(x, dp[i-1][L][F]+1);
                }
            }

    int ans = 0;
    for (int L=0; L<=100; L++)
        ans = max(ans, dp[n][L][100]);

    cout << ans << "\n";

    return 0;
}