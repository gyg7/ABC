#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, w;
	cin >> n >> m;
	
	vector<vector<int>> g(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	cin >> w;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	int V = n * w;
	auto id = [&](int city, int day) {
		return city * w + day;
	};
	vector<vector<int>> G(V);
	for (int city = 0; city < n; ++city) {
		for (int day = 0; day < w; ++day) {
			if (s[city][day] != 'o') continue;
			
			int next_day = (day + 1) % w;
			if (s[city][next_day] == 'o') {
				int u = id(city, day);
				int v = id(city, next_day);
				G[u].push_back(v);
			}
			for (int nb : g[city]) {
				if (s[nb][next_day] == 'o') {
					int u = id(city, day);
					int v = id(nb, next_day);
					G[u].push_back(v);
				}
			}
		}
	}
	vector<int> state(V, 0);
	bool has_cycle = false;
	function<void(int)> dfs = [&](int u) {
		state[u] = 1;
		for (int v : G[u]) {
			if (state[v] == 1) {
				has_cycle = true;
				return;
			}
			if (state[v] == 0) {
				dfs(v);
				if (has_cycle) return;
			}
		}
		state[u] = 2;
	};
	for (int i = 0; i < V; ++i) {
		if (state[i] == 0) {
			dfs(i);
			if (has_cycle) break;
		}
	}
	cout << (has_cycle ? "Yes" : "No") << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
