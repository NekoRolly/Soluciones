#include<bits/stdc++.h>
#include"werewolf.h"
using namespace std;
typedef vector<int> vi;

const int N = 2e5+4;

int n;
vi adj[N];
bool vis1[N],vis2[N];

void dfs1(int u,int l,int r,bool vis[]){
    if (u < l || r < u) return;
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v])
            dfs1(v, l, r, vis);
}

vi rec;
void dfs2(int u,int p){
    rec.push_back(u);
    for (int v : adj[u])
        if (v != p)
            dfs2(v, u);
}

struct Sparce_Table{
    int t[N][18],op; // 0:min 1:max

    int merge(int a,int b){
        return op == 0 ? min(a, b) : max(a, b);
    }

    void build(int n,vi a,int _op){
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

vi check_validity(int N,vi X,vi Y,vi S,vi E,vi L,vi R){
    n = N;

    for (int i=0; i<X.size(); i++){
        adj[X[i]].push_back(Y[i]);
        adj[Y[i]].push_back(X[i]);
    }

    if (n <= 3000 && S.size() <= 3000){
        vi vans;
        for (int j=0; j<S.size(); j++){
            for (int i=0; i<n; i++)
                vis1[i] = vis2[i] = false;

            dfs1(S[j], L[j], n-1, vis1);
            dfs1(E[j], 0, R[j], vis2);

            int ans = 0;
            for (int i=0; i<n; i++)
                if (vis1[i] && vis2[i])
                    ans = 1;

            vans.push_back(ans);
        }

        return vans;
    }
    else{
        int rt;
        for (int i=0; i<n; i++)
            if (adj[i].size() == 1)
                rt = i;

        dfs2(rt, -1);
/*
        cout << "rec: ";
        for (int x : rec)
            cout << x << " ";
        cout << "\n";
*/
        int pos[n];
        for (int i=0; i<n; i++)
            pos[rec[i]] = i;

        spt_max.build(n, rec, 1);
        spt_min.build(n, rec, 0);

        vi vans;
        for (int j=0; j<S.size(); j++){
            int a = pos[S[j]], b = pos[E[j]];

            if (a < b){
                int l = a, r = n;
                while (l+1<r){
                    int m = (l+r)>>1;
                    if (spt_min.query(a, m) >= L[j])
                        l = m;
                    else
                        r = m;
                }
                int aR = l;

                l = -1, r = b;
                while (l+1<r){
                    int m = (l+r)>>1;
                    if (spt_max.query(m, b) <= R[j])
                        r = m;
                    else
                        l = m;
                }
                int bL = r;

                // cout << bL << " <= " << aR << "\n";

                vans.push_back(int(bL <= aR));
            }
            else{
                int l = b, r = n;
                while (l+1<r){
                    int m = (l+r)>>1;
                    if (spt_max.query(b, m) <= R[j])
                        l = m;
                    else
                        r = m;
                }
                int bR = l;

                l = -1, r = a;
                while (l+1<r){
                    int m = (l+r)>>1;
                    if (spt_min.query(m, a) >= L[j])
                        r = m;
                    else
                        l = m;
                }
                int aL = r;

                // cout << a << " a-b " << b << "\n";
                // cout << aL << " <= " << bR << "\n";
                vans.push_back(int(aL <= bR));
            }
        }

        return vans;
    }
}