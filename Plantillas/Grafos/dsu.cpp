#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+4;
const ll M = 1e13;
const ll inf = 1e18;
const int mod = 1e9+7;

struct Dsu{
	int t[N],sz[N];

	void build(int n){
		for (int i=1; i<=n; i++)
			t[i] = i, sz[i] = 1;
	}

	int find(int x){
		return (x == t[x] ? x : t[x] = find(t[x]));
	}

	void join(int a,int b){
		a = find(a), b = find(b);
		if (a != b){
			if (sz[a] > sz[b])
				swap(a, b);
			t[a] = b;
			sz[b] += sz[a];
		}
	}
} dsu;

// dsu rollback
struct Dsu
{
    int n,t[N],sz[N];
    stack<int> d;

    int find(int x){
        return x == t[x] ? x : find(t[x]);
    }

    void join(int a,int b){
        a = find(a);
        b = find(b);
        if (a == b){
            d.push(-1);
            return;
        }
        if (sz[a] > sz[b]){
            swap(a, b);
        }
        t[a] = b;
        sz[b] += sz[a];
        d.push(a);
    }

    void back(){
        if (d.top() != -1){
            int a = d.top();
            int b = t[a];
            t[a] = a;
            sz[b] -= sz[a];
        }
        d.pop();
    }

    Dsu(int n) : n(n) {
        for (int i=0; i<n; i++){
            t[i] = i;
            sz[i] = 1;
        }
    }

    Dsu(){}
};

struct edge{
	int a,b,w;

	bool operator<(edge x){
		return w < x.w;
	}
};