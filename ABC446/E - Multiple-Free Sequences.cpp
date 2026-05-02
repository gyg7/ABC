#include <bits/stdc++.h>
using namespace std;
int m, a, b, vis[1000001];
vector<int> ve[1010 * 1010];
int dfs(int u) {
	if (vis[u]) return 0;
	vis[u] = 1;
	int sz = 1;
	for (int v : ve[u])
		sz += dfs(v);
	return sz;
}
int main() {
	cin >> m >> a >> b;
	for (int x = 1; x < m; x++) {
		for (int y = 1; y < m; y++) {
			int idx = x * 1000 + y;
			int v = (x * b + y * a) % m;
			int to = y * 1000 + v;
			ve[to].push_back(idx);
		}
	}
	int ans = (m-1) * (m-1);
	for (int i = 1; i < m; i++)
		ans -= dfs(i * 1000 + 0)-1;
	cout << ans << endl;
}