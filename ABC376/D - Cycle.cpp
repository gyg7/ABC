#include <bits/stdc++.h>
using namespace std;
int n, m, u, v, ans, d[200001], vis[200001];
vector<int> ve[200001];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		ve[u].push_back(v);
	}
	ans = n + 1;
	for (int i = 1; i <= n; i++)
		sort(ve[i].begin(), ve[i].end());
	priority_queue<pair<int, int>> q;
	q.push({0, 1});
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	while (q.size()) {
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int v : ve[u]) {
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q.push({-d[v], v});
			}
			if (v == 1)
				ans = min(ans, d[u] + 1);
		}
	}
	cout << (ans == n + 1 ? -1 : ans) << endl;
}