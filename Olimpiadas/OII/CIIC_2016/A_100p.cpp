#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1500004;

struct Fenwick_Tree{
    int n,t[N];

    void update(int i,int val){
        for (; i<=n; i+=i&-i) t[i] += val;
    }

    int prefix(int i){
        int ans = 0;
        for (; i>0; i-=i&-i) ans += t[i];
        return ans;
    }
} fwt;

int n;
int val[N];

int leer(){
    int x = 0;
    for (char c = getchar(); '0' <= c && c <= '9'; c = getchar())
        x = x*10 + (c-'0');
    return x;
}

/*
Complejidad: O(n*logn)
Memoria: O(n)
Puntaje: 25 + 25 + 25 + 25 = 100
- Memoria muy limitada
- Requiere lectura muy eficiente
*/
int main(){
    n = leer()/2;

    for (int i=0; i<n; i++){
        int x = leer();
        val[x] = n-i;
    }

    ll ans = 0; fwt.n = n;
    for (int i=0; i<n; i++){
        int x = leer(); x = val[x];
        ans += fwt.prefix(x-1);
        fwt.update(x, 1);
    }

    cout << ans << '\n';

    return 0;
}
