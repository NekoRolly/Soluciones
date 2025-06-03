// RANGE UPDATE, POINT QUERY
#include<bits/stdc++.h>
using namespace std;
 
const int N = 2e5+4;
typedef long long ll;
 
struct Segment_Tree{
    ll t[N*4];
 
    void build(int id,int l,int r,int a[]){
        if (l+1 == r) t[id] = a[l];
        else{
            int m = (l+r)/2;
            build(2*id, l, m, a);
            build(2*id+1, m, r, a);
        }
    }
 
    void update(int id,int l,int r,int x,int y,int val){
        if (x >= y || r <= x || y <= l) return;
        if (x <= l && r <= y) t[id] += val;
        else{
            int m = (l+r)/2;
            update(2*id, l, m, x, y, val);
            update(2*id+1, m, r, x, y, val);
        }
    }
 
    ll query(int id,int l,int r,int pos){
        if (l+1 == r) return t[id];
        int m = (l+r)/2;
        if (pos < m) return t[id] + query(2*id, l, m, pos);
        else return t[id] + query(2*id+1, m, r, pos);
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
        int c,l,r,u,pos;
        cin >> c;
 
        if (c == 1){
            cin >> l >> r >> u;
            sgt.update(1, 1, n+1, l, r+1, u);
        }
        else{
            cin >> pos;
            cout << sgt.query(1, 1, n+1, pos) << "\n";
        }
    }
 
    return 0;
}
