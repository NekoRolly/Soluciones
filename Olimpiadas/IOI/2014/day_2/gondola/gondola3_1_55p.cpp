// Complejidad  : O(nlogn + MX)
// Memoria      : O(n + MX)
// Puntaje      : (5 + 5 + 10) + (0 + 0 + 0) + (5 + 15 + 15 + 0) = 55
#include "gondola.h"
#include<bits/stdc++.h>
using namespace std;
const int MAX = 250004;
const int mod = 1e9+9;

int P(int a,int b){ return 1ll*a*b%mod;}

int valid(int n, int arr[]){
    int pos1 = -1;
    set<int> st;
    for (int i=0; i<n; i++){
        if (arr[i] <= n) pos1 = (i-arr[i]+1 + n)%n;
        st.insert(arr[i]);
    }
    if (st.size() < n) return 0;
    if (pos1 == -1) return 1;
    for (int i=1; i<=n; i++){
        int j = (pos1+i-1)%n;
        if (arr[j] <= n && arr[j] != i) return 0;
    }
    return 1;
}

//----------------------

int replacement(int n, int gondolaSeq[], int replacementSeq[]){
    return -2;
}

//----------------------

bool flag[MAX];
int countReplacement(int n, int arr[]){
    if (valid(n, arr) == 0) return 0;
    int cnt = 0, ans = 1, mx = 0;
    for (int i=0; i<n; i++){
        mx = max(mx, arr[i]);
        if (arr[i] <= n) cnt++;
        else flag[arr[i]] = true;
    }

    if (cnt == 0) ans = n;

    int acum = 0;
    for (int i=mx; i>=n+1; i--){
        if (!flag[i]) ans = P(ans, acum);
        else acum++;
    }

    return ans;
}
