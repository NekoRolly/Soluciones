#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<pii> a,b;

    for (int i=0; i<n; i++){
        int l,r;
        cin >> l >> r;
        a.push_back({l, r});
    }

    for (int i=0; i<m; i++){
        int l;
        cin >> l;
        a.push_back({l, l});
    }

    sort(a.begin(), a.end());

    int L = -1,R;

    for (auto [l, r] : a){
        if (L == -1){
            L = l;
            R = r;
        }
        else if (R+1 >= l)
            R = max(R, r);
        else{
            b.push_back({L, R});
            L = l;
            R = r;
        }
    }
    b.push_back({L, R});

    cout << b.size() << "\n";

    for (auto [l, r] : b){
        cout << l << " " << r << "\n";
    }

    return 0;
}
