#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf = 1e9 + 4;
const ll infll = 1e18 + 4;
const int mod = 1e9 + 7;
const int N = 3e3 + 4;

string s,t;
int n,m;

int dp[N][N];

int Dp(int i,int j){
    if (i == 0 || j == 0) return 0;
    int &x = dp[i][j];
    if (x != -1) return x;
    if (s[i-1] == t[j-1]) x = 1 + Dp(i-1, j-1);
    else x = max(Dp(i-1, j), Dp(i, j-1));
    return x;
}

void getLCS(int i,int j){
    if (i == 0 || j == 0) return;
    if (s[i-1] == t[j-1]){
        getLCS(i-1, j-1); 
        cout << s[i-1];  
    }
    else if (dp[i-1][j] > dp[i][j-1]) getLCS(i-1, j);
    else getLCS(i, j-1);
}

void solve(){
    cin >> s >> t;
    n = s.size(), m = t.size();

    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++)
            dp[i][j] = -1;

    Dp(n, m);
    getLCS(n, m);
    cout << endl;
}  

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int kou = 1;
    // cin >> kou;

    while (kou--)
        solve();

    return 0;
}