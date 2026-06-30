// Complejidad  : O(n*logn + MX)
// Memoria      : O(n + MX)
// Puntaje      : (0 + 0 + 0) + (5 + 10 + 20) + (0 + 0 + 0 + 0) = 35
#include "gondola.h"
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+4;
const int inf = 1e9+4;

int valid(int n, int arr[]){
    return -1;
}

//----------------------

int a[N];
vector<pii> vec;
int replacement(int n, int arr[], int ans[]){
    int pos1 = -1;
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

int countReplacement(int n, int inputSeq[]){
return -3;
}
