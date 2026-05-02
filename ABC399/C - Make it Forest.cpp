#include <bits/stdc++.h>
using namespace std;
int fa[200001], n, m, u, v, ans;
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		u = find(u), v = find(v);
		if (u == v) ++ans;
		else fa[v] = u;
	}
	cout << ans << endl;
	return 0;
}