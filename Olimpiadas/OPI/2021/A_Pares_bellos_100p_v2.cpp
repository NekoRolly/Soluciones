#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int a[3004],b[3004];
int dp[3004][3004];
int cnt_a[3004][3004];
int cnt_b[3004][3004];
int cnt_aa[3004];
int cnt_bb[3005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    
    cin >> m;
    for (int i=1; i<=m; i++)
        cin >> b[i];

    for (int i=1; i<=n; i++){
        cnt_aa[i] = 0;
        for (int j=1; j<i; j++)
            cnt_aa[i] += (a[j] > a[i]);
    }

    for (int i=1; i<=m; i++){
        cnt_bb[i] = 0;
        for (int j=1; j<i; j++)
            cnt_bb[i] += (b[j] > b[i]);
    }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++){
            cnt_a[i][j] = cnt_a[i][j-1] + (b[j] > a[i]);
            cnt_b[i][j] = cnt_b[i-1][j] + (a[i] > b[j]);
        }

    dp[0][0] = 0;
    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++){
            int &x = dp[i][j];
            if (i > 0)
                x = max(x, dp[i-1][j] + cnt_aa[i] + cnt_a[i][j]);
            if (j > 0)
                x = max(x, dp[i][j-1] + cnt_bb[j] + cnt_b[i][j]);
        }

    cout << dp[n][m] << "\n";

    return 0;
}