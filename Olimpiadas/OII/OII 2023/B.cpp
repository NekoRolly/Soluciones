#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+4;

struct Fenwick_Tree{
    int n,t[N*3];

    void update(int i,int val){
        for (; i<=n; i+=i&-i) t[i] += val;
    }

    int prefix(int i){
        int ans = 0;
        for (; i>0; i-=i&-i) ans += t[i];
        return ans;
    }

    int query(int l,int r){
        return prefix(r) - prefix(l-1);
    }
} fwt;

struct Rango{
    int l,r,m;
};

int n;
Rango a[N];
vector<int> cc;
vector<int> Ms[N*3],Rs[N*3];

int get_id(int x){
    return upper_bound(cc.begin(), cc.end(), x) - cc.begin();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++){
        int l,r; cin >> l >> r;
        a[i] = {2*l, 2*r, l+r};
        cc.push_back(a[i].l);
        cc.push_back(a[i].r);
        cc.push_back(a[i].m);
    }

    sort(cc.begin(), cc.end());
    cc.erase(unique(cc.begin(), cc.end()), cc.end());
    fwt.n = cc.size();

    for (int i=0; i<n; i++){
        auto &[l, r, m] = a[i];
        l = get_id(l), r = get_id(r), m = get_id(m);
        Rs[r].push_back(i), Ms[m].push_back(i);
    }

    ll ans = 1ll*n*(n-1)/2;
    vector<int> aux;
    for (int i=1; i<=cc.size(); i++){
        for (int id : Ms[i]){
            auto [l, r, m] = a[id];
            if (!aux.empty())
                ans -= lower_bound(aux.begin(), aux.end(), l) - aux.begin();
            aux.push_back(m);
            ans -= fwt.query(l, fwt.n);
        }
        for (int id : Rs[i]){
            auto [l, r, m] = a[id];
            fwt.update(m, 1);
        }
    }

    cout << ans << '\n';

    return 0;
}
