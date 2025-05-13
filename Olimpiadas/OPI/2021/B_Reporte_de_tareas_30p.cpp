#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int vis[1000004];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<n; i++){
        int l,r;
        cin >> l >> r;
        for (int k=l; k<=r; k++)
            vis[k] = true;
    }

    for (int i=0; i<m; i++){
        int x;
        cin >> x;
        vis[x] = true;
    }

    vector<pair<int,int>> vec;

    int l,r=1;
    while (r<=1000000){
        if (!vis[r]){
            r++;
            continue;
        }
        l = r;
        while (r<=1000000 && vis[r]) r++;
        vec.push_back({l, r-1});
    }

    cout << vec.size() << "\n";
    for (int i=0; i<vec.size(); i++)
        cout << vec[i].first << " " << vec[i].second << "\n";

    return 0;
}