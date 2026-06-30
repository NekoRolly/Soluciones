// Complejidad  : O(n^2 + MX)
// Memoria      : O(n + MX)
// Puntaje      : (0 + 0 + 0) + (5 + 10 + 0) + (0 + 0 + 0 + 0) = 15
#include "gondola.h"
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+4;
const int inf = 1e9+4;

int valid(int n, int arr[]){
    return -1;
}

//----------------------

int a[N];
int replacement(int n, int arr[], int ans[]){
    int pos1 = -1;
    for (int i=0; i<n; i++) if (arr[i] <= n)
        pos1 = (i-arr[i]+1 + n)%n;
    if (pos1 == -1) pos1 = 0;
    for (int i=1; i<=n; i++) a[(pos1+i-1)%n] = i;

    int last = n+1, len = 0;
    while (true){
        int pos = -1;
        for (int i=0; i<n; i++)
            if (a[i] != arr[i] && (pos == -1 || arr[pos] > arr[i]))
                pos = i;
        if (pos == -1) break;
        while (last <= arr[pos]){
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
