// NODO COMPLEJO
#include<bits/stdc++.h>
using namespace std;
 
const int N = 2e5+4;
typedef long long ll;
 
struct node{
    ll max_sub_arr;
    ll max_pr,max_su;
    ll suma;
};
 
struct Segment_Tree{
    node t[N*4];
 
    node op(node a,node b){
        if (a.max_sub_arr == -1) return b;
        if (b.max_sub_arr == -1) return a;
        node ans;
        ans.suma = a.suma + b.suma;
        ans.max_pr = max(a.max_pr, a.suma + b.max_pr);
        ans.max_su = max(a.max_su + b.suma, b.max_su);
        ans.max_sub_arr = max(max(a.max_sub_arr, b.max_sub_arr), a.max_su + b.max_pr);
        return ans;
    }
 
    void build(int id,int l,int r,int a[]){
        if (l+1 == r){
            int aux = max(0, a[l]);
            t[id] = {aux, aux, aux, a[l]};
            return;
        }
        int m = (l+r)/2;
        build(2*id, l, m, a);
        build(2*id+1, m, r, a);
        t[id] = op(t[2*id], t[2*id+1]);
    }
 
    void update(int id,int l,int r,int pos,int val){
        if (l+1 == r){
            int aux = max(0, val);
            t[id] = {aux, aux, aux, val};
            return;
        }
        int m = (l+r)/2;
        if (pos < m) update(2*id, l, m, pos, val);
        else update(2*id+1, m, r, pos, val);
        t[id] = op(t[2*id], t[2*id+1]);
    }
 
    node query(int id,int l,int r,int x,int y){
        if (x >= y || r <= x || y <= l) return {-1, 0, 0, 0};
        if (x <= l && r <= y) return t[id];
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
        int pos,val;
        cin >> pos >> val;
        sgt.update(1, 1, n+1, pos, val);
        cout << sgt.query(1, 1, n+1, 1, n+1).max_sub_arr << "\n";
        // cout << sgt.t[1].max_sub_arr << "\n";
    }
 
    return 0;
}
