#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+4;

int n,k;
vector<int> adj[N];
bool esp[N];
int vis[N];
bool ciclo;
vector<int> vec;

void dfs(int u){
	vis[u] = 1;

	for (int v : adj[u]){
		if (vis[v] == 0)
			dfs(v);
		else if (vis[v] == 1)
			ciclo = true;
	}

	vec.push_back(u);
	vis[u] = 2;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	cin >> n >> k;

	for (int i=0; i<k; i++){
		int x;
		cin >> x;
		esp[x] = true;
	}

	for (int i=1; i<=n; i++){
		int m;
		cin >> m;

		while (m--){
			int x;
			cin >> x;
			adj[i].push_back(x);
		}
	}

	for (int i=1; i<=n; i++)
		if (esp[i] && !vis[i])
			dfs(i);

	if (ciclo)
		cout << "-1\n";
	else{
		cout << vec.size() << "\n";
		for (int x : vec)
			cout << x << " ";
		cout << "\n";
	}

	return 0;
}