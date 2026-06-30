// Complejidad  : O(n)
// Memoria      : O(n)
// Puntaje      : (9 + 0) + (0 + 0) + (0 + 0) + (0 + 0) = 9
// Idea         : Ad Hoc
#include<bits/stdc++.h>
using namespace std;

void solve_p1(){
    int n,d; cin >> n >> d;
    cout << "YES\n";
    for (int i=2; i<=n; i++) cout << "1 " << i << '\n';
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
