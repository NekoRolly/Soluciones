#include<bits/stdc++.h>
#include"seats.h"
using namespace std;

const int N = 1e6+4;
int n,m;
int rows[N],cols[N];

void give_initial_chart(int _n,int _m,vector<int> _rows,vector<int> _cols){
    n = _n, m = _m;
    for (int i=0; i<n*m; i++){
        rows[i] = _rows[i];
        cols[i] = _cols[i];
    }
}

int swap_seats(int a,int b){
    swap(rows[a], rows[b]);
    swap(cols[a], cols[b]);

    int ans = 1;
    int min_row = rows[0], max_row = rows[0];
    int min_col = cols[0], max_col = cols[0];
    for (int i=1; i<n*m; i++){
        min_row = min(min_row, rows[i]);
        max_row = max(max_row, rows[i]);
        min_col = min(min_col, cols[i]);
        max_col = max(max_col, cols[i]);

        int area = (max_row - min_row + 1)*(max_col - min_col + 1);
        if (area == i+1)
            ans++;
            
    }

    return ans;
}