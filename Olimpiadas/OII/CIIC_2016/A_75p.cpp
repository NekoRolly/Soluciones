#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+4;

int n;
int pos[N],b[N];

/*
Complejidad: O(n^2)
Memoria: O(n)
Puntaje: 25 + 25 + 25 + 0 = 75
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n; n /= 2;

    for (int i=0; i<n; i++){
        int x; cin >> x;
        pos[x] = i;
    }
    for (int i=0; i<n; i++) cin >> b[i];

    int ans = 0;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            ans += (pos[b[i]] > pos[b[j]]);

    cout << ans << '\n';

    return 0;
}
