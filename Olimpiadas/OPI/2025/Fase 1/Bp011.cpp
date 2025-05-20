#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Segment_Tree{
    int t[50004*4];
    int lz[50004*4];

    void build(int id,int l,int r,int a[]){
        if (l+1 == r) t[id] = a[l];
        else{
            int m = (l+r)>>1;
            build(id<<1, l, m, a);
            build(id<<1|1, m, r, a);
            t[id] = max(t[id<<1], t[id<<1|1]);
        }
    }

    void pushi(int id,int val){
        t[id] += val;
        lz[id] += val;
    }

    void push(int id){
        pushi(id<<1, lz[id]);
        pushi(id<<1|1, lz[id]);
        lz[id] = 0;
    }

    void update(int id,int l,int r,int x,int y){
        if (x >= y || y <= l || r <= x) return;
        if (x <= l && r <= y) pushi(id, 1);
        else{
            int m = (l+r)>>1;
            push(id);
            update(id<<1, l, m, x, y);
            update(id<<1|1, m, r, x, y);
            t[id] = max(t[id<<1], t[id<<1|1]);
        }
    }

    int query(int id,int l,int r,int x,int y){
        if (x >= y || y <= l || r <= x) return 0;
        if (x <= l && r <= y) return t[id];
        int m = (l+r)>>1;
        push(id);
        return max(query(id<<1, l, m, x, y), query(id<<1|1, m, r, x, y));
    }
} sgt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n >> q;

    int a[n];

    for (int i=0; i<n; i++)
        cin >> a[i];

    sgt.build(1, 0, n, a);
    
    while (q--){
        char c;
        int l,r;
        cin >> c >> l >> r; l--;

        if (c == 'Q')
            cout << sgt.query(1, 0, n, l, r) << "\n";
        else
            sgt.update(1, 0, n, l, r);
    }

    return 0;
}