// Complejidad  : O(nlogn) + O(nLOGN + MAX) + O(nlogn)
// Memoria      : O(n) + O(n + MAX) + O(n)
// Puntaje      : (5 + 5 + 10) + (5 + 10 + 20) + (5 + 15 + 15 + 10) = 100
#include "gondola.h"
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int mod = 1e9+9;
const int N = 1e5+4;

int P(int a,int b){ return 1ll*a*b%mod;}
int BP(int a,int b){
    int ans = 1;
    while (b>0){
        if (b&1) ans = P(ans, a);
        a = P(a, a), b >>= 1;
    }
    return ans;
}

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

int a[N];
int replacement(int n, int arr[], int ans[]){
    int pos1 = -1;
    vector<pii> vec;
    for (int i=0; i<n; i++){
        if (arr[i] <= n) pos1 = (i-arr[i]+1 + n)%n;
        else vec.push_back({arr[i], i});
    }

    if (pos1 == -1) pos1 = 0;
    for (int i=1; i<=n; i++) a[(pos1+i-1)%n] = i;

    sort(vec.begin(), vec.end());

    int last = n+1, len = 0;
    for (auto [val, pos] : vec){
        while (last <= val){
            ans[len++] = a[pos];
            a[pos] = last++;
        }
    }

    return len;
}

//----------------------

int countReplacement(int n, int arr[]){
    if (valid(n, arr) == 0) return 0;
    int ans = 1;
    vector<int> vec;
    for (int i=0; i<n; i++)
        if (arr[i] > n) vec.push_back(arr[i]);

    if (vec.size() == n) ans = n;

    vec.push_back(n);
    sort(vec.begin(), vec.end());

    int base = vec.size()-1;
    for (int i=1; i<vec.size(); i++){
        ans = P(ans, BP(base, vec[i] - vec[i-1] - 1));
        base--;
    }

    return ans;
}
