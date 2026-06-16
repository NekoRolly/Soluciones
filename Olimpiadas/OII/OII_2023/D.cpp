#include<bits/stdc++.h>
using namespace std;
const int N = 304;

struct Node{
    int l,r,c;
};

int n;
int a[N];
int dp[N][N];
vector<Node> vec;

Node solve(int l,int r){
    if (l == r) return {l, l, a[l]};
    int k;
    for (int i=l; i<r; i++)
        if (dp[l][i] + dp[i+1][r-(a[i]==a[r])] == dp[l][r])
            k = i;

    if (a[k] == a[r]){
        Node L = solve(l, k); L.r = r;
        if (k+1<r) vec.push_back(solve(k+1, r-1));
        return L;
    }
    else{
        vec.push_back(solve(l, k));
        return solve(k+1, r);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        dp[i][i-1] = 0, dp[i][i] = 1;
    }

    for (int l=n; l>=1; l--){
        for (int r=l+1; r<=n; r++){
            int &x = dp[l][r]; x = n;
            for (int k=l; k<r; k++)
                x = min(x, dp[l][k] + dp[k+1][r-(a[k]==a[r])]);
        }
    }

    cout << dp[1][n] << '\n';

    vec.push_back(solve(1, n));
    reverse(vec.begin(), vec.end());
    for (Node x : vec)
        cout << x.l << ' ' << x.r << ' ' << x.c << '\n';

    return 0;
}
