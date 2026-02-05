#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
Quiero contar cuántas permutaciones de {1, 2, ..., n} tiene exactamente k pares mágicos
Sea i (1 <= i < n). Un par (a[i], a[i+1]) es un mágico si y solo si a[i] y a[i+1] son impares
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;

    vector<int> p(n);
    for (int i=0; i<n; i++)
        p[i] = i+1; // {1, 2, ..., n}

    int ans = 0;
    do{
        int cont = 0;
        for (int i=0; i+1<n; i++) // O(n)
            if (p[i]%2 == 1 && p[i+1]%2 == 1)
                cont++;

        if (cont == k){
            ans++;
            // for (int x : p) cout << x << " ";
            // cout << "\n";
        }
    } while (next_permutation(p.begin(), p.end())); // O(n!)
    
    cout << ans << "\n";
    // Complejidad final : O(n*n!)

    return 0;
}