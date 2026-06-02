/*
Complejidad: O(n*logn)
Memoria: O(n)
Puntaje: 0 + 20 + 0 = 20
Idea: Desescapar la cadena varias veces
*/
#include<bits/stdc++.h>
using namespace std;

string desescapar(string &s){
    string t; int n = s.size();
    for (int i=0; i<n; i++){
        if (s[i] != 'x'){
            t += s[i];
            continue;
        }
        if (i == n-1 || s[i+1] != 'x') return "-1";
        t += 'x', i++;
    }
    return t;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,t,ans; cin >> s;
    t = desescapar(s);

    if (t == s){
        cout << "1\n" << s << '\n';
        return 0;
    }
    if (t == "-1"){
        cout << "0\nNOSTRING\n";
        return 0;
    }

    int cnt = 0;
    for (ans = t; t != "-1"; t = desescapar(t))
        ans = min(ans, t), cnt++;

    cout << cnt << '\n' << ans << '\n';

    return 0;
}
