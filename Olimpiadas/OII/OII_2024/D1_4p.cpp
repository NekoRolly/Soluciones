/*
Complejidad: O(n + q)
Memoria: O(n)
Puntaje: 4 + 0 + 0 + 0 = 4
Idea: La respuesta es solo 1 o 2
Nota: Caso cuando r-l <= 5
*/
#include<bits/stdc++.h>
using namespace std;

int n,q;
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s >> q;
    s = '.' + s;

    while (q--){
        int l,r; cin >> l >> r;
        string t = s.substr(l, r-l+1);
        sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());
        cout << (t == "aeiou" ? 2 : 1) << '\n';
    }

    return 0;
}
