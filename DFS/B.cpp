#include<bits/stdc++.h>
using namespace std;

const int N = 2e3+4;

int n;
vector<int> adj[N],roots;
int ans;

void dfs(int u,int depth){
	ans = max(ans, depth);

	for (int v : adj[u])
		dfs(v, depth+1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i=1; i<=n; i++){
		int p;
		cin >> p;

		if (p != -1)
			adj[p].push_back(i);
		else
			roots.push_back(i);
	}

	for (int rt : roots)
		dfs(rt, 1);

	cout << ans << "\n";

	return 0;
}