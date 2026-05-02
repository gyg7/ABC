#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, u, v;
ll w;
struct egde {
	int nxt, to;
	ll val;
} e[10001];
int head[11], cur;
void add(int u, int v, ll w) {
	e[++cur].nxt = head[u];
	e[head[u] = cur].to = v;
	e[cur].val = w;
}
int vis[11];
bool found;
ll ans;
void dfs(int u, int ff, ll sum) {
	if (u == n) {
		if (found == 0) {
			ans = sum;
			found = 1;
		}
		ans = min(ans, sum);
		return ;
	}
	if (vis[u]) return;
	vis[u] = 1;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (vis[v]) continue;
		dfs(v, u, sum ^ e[i].val);
	}
	vis[u] = 0;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	dfs(1, 0, 0);
	cout << ans << endl;
	return 0;
}