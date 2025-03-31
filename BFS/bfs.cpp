#include<bits/stdc++.h>
using namespace std;

void print_cola(queue<int> q){
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    int dis[n+1];

    while (m--){
        int a,b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    queue<int> qu;
    qu.push(4);

    for (int i=1; i<=n; i++)
        dis[i] = -1;

    dis[4] = 0;

    while (!qu.empty()){
        int u = qu.front();
        // print_cola(qu);
        qu.pop();

        for (int v : adj[u])
            if (dis[v] == -1){
                qu.push(v);
                dis[v] = dis[u] + 1;
            }
    }

    for (int i=1; i<=n; i++)
        cout << dis[i] << " - ";
    cout << "\n";


    return 0;
}

/*
7 8
5 1
5 7
6 5
4 2
2 5
5 4
3 6
4 3

6 8
1 2
1 3
1 4
1 5
2 6
3 6
4 6
5 6
*/