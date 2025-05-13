#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int a[3004],b[3004];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    
    cin >> m;
    for (int i=0; i<m; i++)
        cin >> b[i];

    int ans = 0;
    for (int mask=1; mask<(1<<(n+m)); mask++){
        if (__builtin_popcount(mask) != n) continue;
        vector<int> arr;
        int i=0,j=0;
        for (int id=0; id<n+m; id++){
            if (mask>>id&1)
                arr.push_back(a[i++]);
            else
                arr.push_back(b[j++]);
        }

        int inv = 0;
        for (int i=0; i<n+m; i++)
            for (int j=0; j<i; j++)
                inv += arr[j] > arr[i];
        ans = max(ans, inv);
    }

    cout << ans << "\n";

    return 0;
}