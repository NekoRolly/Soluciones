#include<bits/stdc++.h>
#include"seats.h"
using namespace std;
const int N = 1e6+4;
const int inf = 1e9+4;


int max_row[N], min_row[N], max_col[N], min_col[N];
int is[N],ans;

int n,m;
int rows[N],cols[N];

void give_initial_chart(int _n,int _m,vector<int> _rows,vector<int> _cols){
    n = _n, m = _m;
    for (int i=0; i<n*m; i++){
        rows[i] = _rows[i];
        cols[i] = _cols[i];
    }

    min_row[0] = max_row[0] = rows[0];
    min_col[0] = max_col[0] = cols[0];
    is[0] = ans = 1;

    for (int i=1; i<n*m; i++){
        min_row[i] = min(min_row[i-1], rows[i]);
        max_row[i] = max(max_row[i-1], rows[i]);
        min_col[i] = min(min_col[i-1], cols[i]);
        max_col[i] = max(max_col[i-1], cols[i]);

        int height = max_row[i] - min_row[i] + 1;
        int width = max_col[i] - min_col[i] + 1;
        int area = height * width;

        is[i] = (area == i+1);
        ans += is[i];
    }
}

int swap_seats(int a,int b){
    if (a > b) swap(a, b);
    swap(rows[a], rows[b]);
    swap(cols[a], cols[b]);

    for (int i=a; i<=b; i++)
        ans -= is[i];

    if (a == 0){
        min_row[0] = max_row[0] = rows[0];
        min_col[0] = max_col[0] = cols[0];
        a++, ans++;
    }

    for (int i=a; i<=b; i++){
        min_row[i] = min(min_row[i-1], rows[i]);
        max_row[i] = max(max_row[i-1], rows[i]);
        min_col[i] = min(min_col[i-1], cols[i]);
        max_col[i] = max(max_col[i-1], cols[i]);

        int height = max_row[i] - min_row[i] + 1;
        int width = max_col[i] - min_col[i] + 1;
        int area = height * width;

        is[i] = (area == i+1);
        ans += is[i];
    }

    return ans;
}