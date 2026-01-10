#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 3004;

int n,m;
int a[N],b[N];
int inv_a[N],inv_b[N];
int inv_a_b[N][N],inv_b_a[N][N];
int dp[N][N];

/*
inv_a[i] : cantidad de 1 <= k <= i tal que a[k] > a[i]
inv_b[j] : cantidad de 1 <= k <= j tal que b[k] > b[j]

inv_a_b[i][j] : cantidad de 1 <= k <= j tal que b[k] > a[i]
inv_b_a[i][j] : cantidad de 1 <= k <= i tal que a[k] > b[j]

dp[i][j] :  mayor cantidad de pares bellos que se pueden lograr combinando
            los primeros i elementos de a y los primeros j elementos de b

Para mayor entendimiento se relaciona usualmente el arreglo a con
el índice i y el arreglo b con el índice j.
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    cin >> m;
    for (int j=1; j<=m; j++)
        cin >> b[j];

    for (int i=1; i<=n; i++){
        inv_a[i] = 0;
        for (int k=1; k<i; k++)
            inv_a[i] += a[k] > a[i]; // O(n*n)

        dp[i][0] = dp[i-1][0] + inv_a[i]; // caso base del dp

        for (int j=1; j<=m; j++) // O(n*m)
            inv_a_b[i][j] = inv_a_b[i][j-1] + (b[j] > a[i]);
    }

    for (int j=1; j<=m; j++){
        inv_b[j] = 0;
        for (int k=1; k<j; k++) // O(m*m)
            inv_b[j] += b[k] > b[j];

        dp[0][j] = dp[0][j-1] + inv_b[j]; // caso base del dp

        for (int i=1; i<=n; i++) // O(n*m)
            inv_b_a[i][j] = inv_b_a[i-1][j] + (a[i] > b[j]);
    }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++){ // O(n*m)
            dp[i][j] = max( dp[i][j-1] + inv_b[j] + inv_b_a[i][j],
                            dp[i-1][j] + inv_a[i] + inv_a_b[i][j]);
        }

    cout << dp[n][m] << "\n";

    return 0;
}
