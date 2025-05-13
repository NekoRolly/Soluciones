#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int a[3004],b[3004];
int dp[3004][3004];

/*
    dp[i][j] : mayor número de inversiones de un arreglo formado por
               los primeros i valores de a
               los primeros j valores de b

    dp[i][j] <- dp[i-1][j]
*/

int Dp(int i,int j){
    if (i == 0 && j == 0) return 0;
    int &x = dp[i][j];
    if (x != -1) return x;
    if (i > 0){
        int cnt = 0;
        for (int k=1; k<i; k++)
            cnt += (a[k] > a[i]);
        for (int k=1; k<=j; k++)
            cnt += (b[k] > a[i]);
        x = max(x, Dp(i-1, j) + cnt);
    }
    if (j > 0){
        int cnt = 0;
        for (int k=1; k<=i; k++)
            cnt += (a[k] > b[j]);
        for (int k=1; k<j; k++)
            cnt += (b[k] > b[j]);
        x = max(x, Dp(i, j-1) + cnt);
    }
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

    memset(dp, -1, sizeof dp);
    cout << Dp(n, m) << "\n";

    return 0;
}