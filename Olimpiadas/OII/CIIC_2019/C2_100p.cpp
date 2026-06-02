/*
Complejidad: O(n*logn + k^2 + q*(logn + 30))
Memoria: O(n + k^2)
Puntaje: 5 + 8 + 10 + 35 + 42 = 100
Idea: Lista Enlazada para optimizar query 1
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500004;
const int K = 104;

struct Linked_List{
    int L[N],R[N];

    void build(int n){
        for (int i=1; i<=n; i++)
            L[i] = i-1, R[i] = i+1;
    }

    void move(int x,int y){
        L[R[x]] = L[x], R[L[x]] = R[x];
        int l = L[y];
        R[l] = x, L[x] = l;
        L[y] = x, R[x] = y;
    }
} lst;

int n,k,q;
map<string,int> id;
int fav[N];
int a[K][K];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> q;

    for (int i=1; i<=n; i++){
        string s; int x;
        cin >> s >> fav[i];
        id[s] = i;
    }
    lst.build(n);

    for (int i=1; i<=k; i++)
        for (int j=1; j<=k; j++)
            cin >> a[i][j];

    while (q--){
        int c,x; cin >> c;
        string s,t;

        if (c == 1){
            cin >> s >> t;
            lst.move(id[s], id[t]);
        }
        else if (c == 2){
            cin >> s >> x;
            fav[id[s]] = x;
        }
        else{
            cin >> s;
            x = id[s];
            ll ans = 0;
            for (int i=0,y=lst.L[x]; y!=0 && i<30; i++,y=lst.L[y])
                ans += a[fav[y]][fav[x]] / (1<<i);
            for (int i=0,y=lst.R[x]; y!=n+1 && i<30; i++,y=lst.R[y])
                ans += a[fav[y]][fav[x]] / (1<<i);
            cout << ans << '\n';
        }
    }

    return 0;
}
