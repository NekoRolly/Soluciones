// Complejidad  : O(n)
// Memoria      : O(n)
// Puntaje      : (9 + 21) + (0 + 0) + (0 + 0) + (0 + 0) = 30
// Idea         : Ad Hoc
#include<bits/stdc++.h>
using namespace std;

void solve_p1(){
    int n,d; cin >> n >> d;
    int k = n/2;
 
    if (d == 1){
        if (n == 2) cout << "YES\n1 2\n";
        else cout << "NO\n";
        return;
    }
 
    if (d > k+1){ cout << "NO\n"; return;}
    cout << "YES\n";
 
    for (int i=2,p; i<=n; i++){
        if (i <= d) p = i-1;
        else if (i >= n+1-(d-1)) p = n+1-i;
        else p = 1;
        cout << p << ' ' << i << '\n';
    }
}

void solve_p2(){
}

void solve(){
    int p; cin >> p;
    if (p == 1) solve_p1();
    else solve_p2();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int suki; cin >> suki;
    while (suki--) solve();

    return 0;
}
