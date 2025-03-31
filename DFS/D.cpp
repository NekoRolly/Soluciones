#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+4;
const int mod = 1e9+7;

int S(int a,int b){
	return (a+b)%mod;
}

int P(int a,int b){
	return 1ll*a*b%mod;
}

int n,k;
vector<int> adj[N];
int cnt;
bool vis[N];

int get(int x){ // retorna x^k
	int ans = 1;
	for (int i=0; i<k; i++)
		ans = P(ans, x);
	return ans;
}

void dfs(int u){
	vis[u] = true;
	cnt++;

	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i=1; i<n; i++){
		int a,b,w;
		cin >> a >> b >> w;

		if (w == 0){
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}

	int ans = get(n); // n^k

	for (int i=1; i<=n; i++)
		if (!vis[i]){
			cnt = 0;
			dfs(i);
			ans = S(ans, mod-get(cnt));
		}

	cout << ans << "\n";

	return 0;
}
