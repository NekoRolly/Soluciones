#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
Quiero contar cuántas permutaciones de {1, 2, ..., n} tiene exactamente k pares mágicos
Sea i (1 <= i < n). Un par (a[i], a[i+1]) es un mágico si y solo si a[i] y a[i+1] son impares
*/

int n,k,ans;
vector<int> p;
bool usado[40];

void generar(int i){
    if (i == n){
        int cont = 0;
        for (int i=0; i+1<n; i++) // O(n)
            if (p[i]%2 == 1 && p[i+1]%2 == 1)
                cont++;
        if (cont == k) ans++;
        return;
    }

    for (int x=1; x<=n; x++)
        if (!usado[x]){
            // modifico p[] y usado[] luego de agregar x en la posición i
            p.push_back(x);
            usado[x] = true;
            generar(i+1);

            // modifico p[] y usado[] luego de quitar x de la posición i
            p.pop_back();
            usado[x] = false;
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    generar(0);
    
    cout << ans << "\n";
    // Complejidad final : O(n*n!)

    return 0;
}