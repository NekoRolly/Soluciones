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

int Dp(int i,int j){
    if (i == 0 && j == 0) return 0;
    int &x = dp[i][j];
    if (x != -1) return x;
    if (i > 0)
        x = max(x, Dp(i-1, j) + cnt_a[i][j] + cnt_aa[i]);
    if (j > 0)
        x = max(x, Dp(i, j-1) + cnt_b[i][j] + cnt_bb[j]);
    return x;
}

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

    memset(dp, -1, sizeof dp);
    cout << Dp(n, m) << "\n";

    return 0;
}