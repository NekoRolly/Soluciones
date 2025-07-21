#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+4;
// N < 2^15
// indexado en 0, se puede hacer para indexado en 1 de manera similar
// Build : O(nlogn)
// Query : O(1)
// No hay updates

struct Sparce_Table{ 
    int t[N][18]; // es similar para max

    void build(int n,int a[]){
        for (int i=0; i<n; i++)
            t[i][0] = a[i];
        
        for (int j=0; j+1<18; j++)
            for (int i=0; i<n; i++)
                t[i][j+1] = min(t[i][j], t[min(n-1, i+(1<<j))][j]);
    }

    int query(int l,int r){
        int k = 31 - __builtin_clz(r-l+1);
        return min(t[l][k], t[r-(1<<k)+1][k]);
    }
} spt;

struct Sparce_Table{ 
    int t[N][18],op; // 0:min 1:max

    int merge(int a,int b){
        return op == 0 ? min(a, b) : max(a, b);
    }

    void build(int n,int a[],int _op){
        op = _op;
        for (int i=0; i<n; i++)
            t[i][0] = a[i];
        
        for (int j=0; j+1<18; j++)
            for (int i=0; i<n; i++)
                t[i][j+1] = merge(t[i][j], t[min(n-1, i+(1<<j))][j]);
    }

    int query(int l,int r){
        int k = 31 - __builtin_clz(r-l+1);
        return merge(t[l][k], t[r-(1<<k)+1][k]);
    }
} spt_max, spt_min;
