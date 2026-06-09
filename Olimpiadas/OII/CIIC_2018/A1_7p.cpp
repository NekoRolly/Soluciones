/*
Complejidad: O(n)
Memoria: O(n)
Puntaje: 7 + 0 + 0 = 7
Idea: Todos los números con signo positivo
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+4;

int n,ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    ans = 0;
    for (int i=0; i<2*n; i++){
        int x; cin >> x;
        ans += abs(x);
    }

    cout << ans << '\n';

    return 0;
}
