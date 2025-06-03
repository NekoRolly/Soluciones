// POINT UPDATE, RANGE QUERY
#include<bits/stdc++.h>
using namespace std;
 
const int N = 2e5+4;
typedef long long ll;
 
struct Segment_Tree{
    ll t[4*N];
 
    ll op(ll a,ll b){
        return a + b;
    }
 
    void build(int id,int l,int r,int a[]){
        if (l+1 == r) t[id] = a[l];
        else{   
            int m = (l+r)/2;
            build(2*id, l, m, a);
            build(2*id+1, m, r, a);
            t[id] = op(t[id*2], t[id*2+1]);
        }
    }
 
    void update(int id,int l,int r,int pos,int val){
        if (l+1 == r) t[id] = val;
        else{
            int m = (l+r)/2;
            if (pos < m) update(2*id, l, m, pos, val);
            else update(2*id+1, m, r, pos, val);
            t[id] = op(t[2*id], t[2*id+1]);
            // t[id] = t[id<<1] + t[id<<1|1];
        }
    }
 
    ll query(int id,int l,int r,int x,int y){
        if (x >= y) return 0;
        if (x <= l && r <= y) return t[id];
        if (y <= l || r <= x) return 0;
        int m = (l+r)/2;
        return op(query(2*id, l, m, x, y), query(2*id+1, m, r, x, y));
    }
} sgt;
 
int n,q;
int a[N];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> q;
 
    for (int i=1; i<=n; i++)
        cin >> a[i];
 
    sgt.build(1, 1, n+1, a);
 
    while (q--){
        int c,l,r,pos,val;
        cin >> c;
 
        if (c == 1){
            cin >> pos >> val;
            sgt.update(1, 1, n+1, pos, val);
        }
        else{
            cin >> l >> r;
            cout << sgt.query(1, 1, n+1, l, r+1) << "\n";
        }
    }
 
    return 0;
