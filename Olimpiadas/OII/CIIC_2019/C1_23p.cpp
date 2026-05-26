/*
Complejidad: O(n*logn + k^2 + q1*n + q*(logn+30))
Memoria: O(n + k^2)
Puntaje: 5 + 8 + 10 + 0 + 0 = 23
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500004;
const int K = 104;

int n,k,q;
map<string,int> id;
int fav[N],pos[N];
int a[K][K];
vector<int> vec;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> q;

    for (int i=0; i<n; i++){
        string s; int x;
        cin >> s >> fav[i];
        id[s] = pos[i] = i;
        vec.push_back(i);
    }

    for (int i=1; i<=k; i++)
        for (int j=1; j<=k; j++)
            cin >> a[i][j];

    while (q--){
        int c,x; cin >> c;
        string s,t;

        if (c == 1){
            cin >> s >> t;
            auto it = find(vec.begin(), vec.end(), id[s]);
            vec.erase(it);
            it = find(vec.begin(), vec.end(), id[t]);
            vec.insert(it, id[s]);
            for (int i=0; i<n; i++) pos[vec[i]] = i;
        }
        else if (c == 2){
            cin >> s >> x;
            fav[id[s]] = x;
        }
        else{
            cin >> s; x = pos[id[s]];
            ll ans = 0;
            for (int i=0,e2=1; i<30; i++,e2*=2){
                if (x-i-1 >= 0) ans += a[fav[vec[x]]][fav[vec[x-i-1]]] / e2;
                if (x+i+1 < n) ans += a[fav[vec[x]]][fav[vec[x+i+1]]] / e2;
            }
            cout << ans << '\n';
        }
    }

    return 0;
}
