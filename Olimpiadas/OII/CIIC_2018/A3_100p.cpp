/*
Complejidad: O(n)
Memoria: O(n)
Puntaje: 7 + 43 + 50 = 100
Idea: analizar y llegar a una invariante
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+4;

int n,ans1,ans2;
int a[2*N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i=0; i<2*n; i++) cin >> a[i];

    for (int i=0; i<n; i++){
        ans1 += abs(a[i] + a[i+n]);
        ans2 += abs(a[i] - a[i+n]);
    }

    cout << max(ans1, ans2) << '\n';

    return 0;
}
