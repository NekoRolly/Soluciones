#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    while (q--){
        char c;
        int l,r;
        cin >> c >> l >> r;
        l--; r--;

        if (c == 'Q'){
            int ans = 0;
            for (int i=l; i<=r; i++)
                ans = max(ans, a[i]);
            cout << ans << "\n";
        }
        else if (c == 'A'){
            for (int i=l; i<=r; i++)
                a[i]++;
        }
        else if (c == 'R'){
            int mx = 0;
            for (int i=0; i<n; i++)
                mx = max(mx, a[i]);
            for (int i=l; i<=r; i++)
                if (a[i] == mx)
                    a[i] = 0;
        }
        else{
            int x = a[r];
            a.erase(a.begin()+r);
            a.insert(a.begin()+l, x);
        }
    }

    return 0;
}