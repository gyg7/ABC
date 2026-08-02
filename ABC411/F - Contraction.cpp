#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010;
int n, m, fa[maxn];
unordered_set<int> N[maxn];
pair<int, int> edge[maxn];
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		N[u].insert(v);
		N[v].insert(u);
		edge[i] = {u, v};
	}
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	int q;
	cin >> q;
	int now = m;
	for (int i = 1; i <= q; i++) {
		int id;
		cin >> id;
		int x = find(edge[id].first);
		int y = find(edge[id].second);
		if (x != y) {
			if (N[y].size() > N[x].size()) swap(x, y);
			for (int to : N[y]) {
				if (to == x) {
					N[to].erase(y);
					now--;
				} else if (N[x].count(to)) {
					N[to].erase(y);
					now--;
				} else {
					N[x].insert(to);
					N[to].insert(x);
					N[to].erase(y);
				}
			}
			N[y].clear();
			fa[y] = x;
		}
		cout << now << endl;
	}
	return 0;
}