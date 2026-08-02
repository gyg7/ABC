#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int n;
int x[N], head[N], tot;
struct egde {
	int nxt, to, val;
} e[2 * N];
int sz[N], ans;
void dfs(int u, int f) {
	sz[u] = x[u];
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == f) continue;
		dfs(v, u);
		ans += e[i].val * abs(sz[v]);
		sz[u] += sz[v];
	}
}
signed main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for (int i = 1; i < n; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		e[++tot] = {head[x], y, w};
		head[x] = tot;
		e[++tot] = {head[y], x, w};
		head[y] = tot;
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}