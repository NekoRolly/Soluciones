#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int a[3004],b[3004];
int ans;

vector<int> arr;
void rec(int i,int j){
    if (i == n && j == m){
        int inv = 0;
        for (int i=0; i<n+m; i++)
            for (int j=0; j<i; j++)
                inv += arr[j] > arr[i];
        ans = max(ans, inv);
        return;
    }
    if (i < n){
        arr.push_back(a[i]);
        rec(i+1, j);
        arr.pop_back();
    }
    if (j < m){
        arr.push_back(b[j]);
        rec(i, j+1);
        arr.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    
    cin >> m;
    for (int i=0; i<m; i++)
        cin >> b[i];

    rec(0, 0);
    cout << ans << "\n";

    return 0;
}