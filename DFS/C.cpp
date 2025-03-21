#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int N = 1e2+4;

int n;
vector<int> adj[N];
pii p[N];
bool vis[N];

void dfs(int u){
	vis[u] = true;

	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i=0; i<n; i++){
		cin >> p[i].first >> p[i].second;

		for (int j=0; j<i; j++)
			if (p[i].first == p[j].first || p[i].second == p[j].second){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
	}

	int cnt = 0;
	for (int i=0; i<n; i++)
		if (!vis[i]){
			dfs(i);
			cnt++;
		}

	cout << cnt-1 << "\n";

	return 0;
}