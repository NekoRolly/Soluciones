#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+4;

struct Node{
    ll dx,dy,dir;

    Node operator+(Node o){
        Node ans;
        int new_dir = (dir + o.dir)%4;
        if (dir == 0) ans = {dx + o.dx, dy + o.dy, new_dir};
        else if (dir == 1) ans = {dx - o.dy, dy + o.dx, new_dir};
        else if (dir == 2) ans = {dx - o.dx, dy - o.dy, new_dir};
        else ans = {dx + o.dy, dy - o.dx, new_dir};
        return ans;
    }
};

struct Segment_Tree{
    int n;
    Node t[N*2];

    void build(int sz,Node a[]){ n = sz;
        for (int i=0; i<n; i++) t[i+n] = a[i];
        for (int i=n-1; i>0; i--) t[i] = t[i<<1] + t[i<<1|1];
    }

    void update(int i,Node x){
        for (t[i+=n] = x; i>>=1; ) t[i] = t[i<<1] + t[i<<1|1];
    }

    Node query(int l,int r){
        Node ansL,ansR; ansL = ansR = {0, 0, 0};
        for (l+=n, r+=n; l<r; l>>=1, r>>=1){
            if (l&1) ansL = ansL + t[l++];
            if (r&1) ansR = t[--r] + ansR;
        }
        return ansL + ansR;
    }
} sgt;

int n,q;
Node a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i=0; i<n; i++){
        int t,m; cin >> t >> m;
        if (t == 1) a[i] = {m, 0, 0};
        else a[i] = {0, 0, m};
    }

    sgt.build(n, a);

    cin >> q;
    while (q--){
        int tq,l,r,i,t,m;
        cin >> tq;
        if (tq == 1){
            cin >> l >> r;
            Node x = sgt.query(l, r+1);
            cout << x.dx << ' ' << x.dy << ' ' << x.dir << '\n';
        }
        else{
            cin >> i >> t >> m;
            if (t == 1) sgt.update(i, {m, 0, 0});
            else sgt.update(i, {0, 0, m});
        }
    }

    return 0;
}
