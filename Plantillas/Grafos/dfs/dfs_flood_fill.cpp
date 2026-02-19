#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6+4;
const int inf = 1e9+4;

int n,m;
char lab[N];
vector<int> adj;
string adj_dir;
int dis[N];
int up[N];
int A,B;

bool check(int u,int v){
    return 0 <= v && v < n*m && abs(u/m - v/m) + abs(u%m - v%m) == 1 && lab[v] != '#';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    if (m>1) adj = {+m, -m, +1, -1};
    else adj = {+1, -1};
    adj_dir = "DURL";

    for (int i=0; i<n*m; i++){
        cin >> lab[i];
        if (lab[i] == 'A') A = i;
        if (lab[i] == 'B') B = i;
    }

    fill(dis, dis+n*m, inf);
    
    queue<int> qu;
    qu.push(A);
    dis[A] = 0;
    up[A] = -1;

    while (!qu.empty()){
        int u = qu.front();
        qu.pop();
        for (int var : adj){
            int v = u+var;
            if (check(u, v) && dis[v] > dis[u]+1){
                dis[v] = dis[u]+1;
                up[v] = u;
                qu.push(v);
            }
        }
    }

    if (dis[B] == inf)
        cout << "NO\n";
    else{
        cout << "YES\n";
        string s;
        
        int v = B;
        while (v != A){
            int u = up[v];
            for (int i=0; i<adj.size(); i++)
                if (u + adj[i] == v)
                    s += adj_dir[i];
            v = u;
        }
        reverse(s.begin(), s.end());
        cout << s.size() << "\n" << s << "\n";
    }


    return 0;
}