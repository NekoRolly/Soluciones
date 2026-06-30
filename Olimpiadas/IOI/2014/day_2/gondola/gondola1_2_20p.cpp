// Complejidad  : O(nlogn)
// Memoria      : O(n)
// Puntaje      : (5 + 5 + 10) + (0 + 0 + 0) + (0 + 0 + 0 + 0) = 20
#include "gondola.h"
#include<bits/stdc++.h>
using namespace std;

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

int countReplacement(int n, int inputSeq[]){
return -3;
}
