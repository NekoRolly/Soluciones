// Complejidad  : O(n)
// Memoria      : O(n)
// Puntaje      : (5 + 5 + 0) + (0 + 0 + 0) + (0 + 0 + 0 + 0) = 10
#include "gondola.h"
#include<bits/stdc++.h>
using namespace std;

int valid(int n, int arr[]){
    int pos1 = -1;
    for (int i=0; i<n; i++)
        if (arr[i] == 1) pos1 = i;
    if (pos1 == -1) return 0;
    for (int i=1; i<=n; i++)
        if (arr[(pos1+i-1)%n] != i) return 0;
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
