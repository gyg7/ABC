#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200001;
int n, m, u, v;
set<pair<int, int>> ve[N];
int deg[N], cnt[N];
bool vis[N];
void dfs(int u, int l) {
	if (u == n) {
		cnt[l]++;
		return;
	}
	for (auto [v, w] : ve[u]) {
		if (vis[v] == 0) {
			vis[v] = 1;
			dfs(v, l + w);
			vis[v] = 0;
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		ve[u].insert({v, 1});
		ve[v].insert({u, 1});
	}
	queue<int> q;
	for (int i = 2; i < n; i++)
		if (ve[i].size() == 1)
			q.push(i);
	while (q.size()) {
		int u = q.front();
		q.pop();
		int to = ve[u].begin()->first;
		ve[to].erase({u, 1});
		if (to != 1 && to != n && ve[to].size() == 1) q.push(to);
	}
	for (int i = 2; i < n; i++) {
		if (ve[i].size() == 2) {
			auto [u, w1] = *ve[i].begin();
			auto [v, w2] = *next(ve[i].begin());
			ve[u].erase(ve[u].find({i, w1}));
			ve[v].erase(ve[v].find({i, w2}));
			ve[u].insert({v, w1 + w2});
			ve[v].insert({u, w1 + w2});
		}
	}
	vis[1] = 1;
	dfs(1, 0);
	for (int i = 1; i <= n - 1; i++)
		printf("%lld%c", cnt[i], " \n"[i == n - 1]);
	return 0;
}

