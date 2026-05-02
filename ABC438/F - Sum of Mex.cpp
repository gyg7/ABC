#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, u, v, sz[200001], vis[200001], fa[200001];
vector<int> ve[200001];
void dfs(int u) {
	sz[u] = 1;
	for (int v : ve[u]) {
		if (v == fa[u]) continue;
		fa[v] = u;
		dfs(v);
		sz[u] += sz[v];
	}
}
signed main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		fa[u] = fa[v] = -1;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	dfs(0);
	long long ans = n * (n + 1) / 2;
	for (int i : ve[0])
		ans -= sz[i] * (sz[i] + 1) / 2;
	int saved = -1, deepst1=0, deepst2=0;
	vis[0] = 1;
	for (int i = 1; i < n; i++) {
		if (vis[i])
			ans += saved * sz[deepst1];
		else {
			int cur = i, p;
			while (vis[i] == 0) {
				p = i;
				vis[i] = 1;
				i = fa[i];
			}
			if (i != deepst1 && i != deepst2) break;
			if (i == deepst1) {
				deepst1 = cur;
				if (saved == -1) saved = n - sz[p];

			} else if (i == deepst2) {
				deepst2 = cur;
				saved = sz[deepst2];
			}
//			if (saved == -1) saved = n - sz[p];
			ans += saved * sz[deepst1];
			i = cur;
		}
	}
	cout << ans << endl;
}