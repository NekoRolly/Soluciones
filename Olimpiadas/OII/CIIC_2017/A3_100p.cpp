/*
Complejidad: O(D)
Memoria: O(min(D, k))
Puntaje: 25 + 25 + 25 + 25 = 100
Idea: DP con transición O(1) y optimización de memoria
*/
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000;

int d,k,sum;
queue<int> qu;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> d;

    qu.push(1); sum = 1;
    for (int i=1; i<min(d, k); i++){
        qu.push(sum % mod);
        sum = (2*sum) % mod;
    }

    for (int i=0; i<d-k; i++){
        int R = sum, L = qu.front();
        qu.push(R); qu.pop();
        sum = (sum + R - L + mod) % mod;
    }

    cout << sum << '\n';

    return 0;
}
