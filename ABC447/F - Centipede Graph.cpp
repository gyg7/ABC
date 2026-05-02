#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, x, y, ans;
vector<int> ve[N];
int deg[N], f[N];
void dfs1(int u, int f) {
	for (int v : ve[u]) {
		if (v == f) continue;
		dfs1(v, u);
	}
}
void dfs2(int u, int fa) {
	f[u] = 0;
	if (deg[u] >= 3) f[u] = 1;
	int mx1 = 0, mx2 = 0;
	for (int v : ve[u]) {
		if (v == fa) continue;
		dfs2(v, u);
		if (f[v] > mx1) {
			mx2 = mx1;
			mx1 = f[v];
		} else if (f[v] > mx2) mx2 = f[v];
	}
	if (deg[u] >= 3) {
		if (mx1)
			ans = max(ans, mx1 + 1);
	}
	if (deg[u] >= 4) {
		if (mx1 && mx2) ans = max(ans, 1 + mx1 + mx2);
		if (mx1) f[u] = 1 + mx1;
	}
}
void slove() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ve[i].clear();
		deg[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		ve[x].push_back(y);
		ve[y].push_back(x);
		++deg[x], ++deg[y];
	}
	dfs1(1, -1);
	ans = 0;
	for (int i = 1; i <= n; i++)
		if (deg[i] >= 2) {
			ans = 1;
			break;
		}
	dfs2(1, -1);
	cout << ans << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		slove();
	}
}