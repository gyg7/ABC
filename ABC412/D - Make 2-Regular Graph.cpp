#include <bits/stdc++.h>
using namespace std;
int n, m;
bool f[10][10], g[10][10];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		if (u > v) swap(u, v);
		f[u][v] = true;
	}
	vector<int> a;
	a.assign(n, 0);
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	int ans = 0x3f3f3f3f;
	do {
		memset(g, 0, sizeof g);
		for (int i = 0; i < n; i++) {
			int j = (i + 1) % n;
			int u = a[i], v = a[j];
			if (u > v) swap(u, v);
			g[u][v] = true;
		}
		int c0 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i][j] != f[i][j]) c0++;
			}
		}
		ans = min(ans, c0);
		for (int d = 3; d <= n - 3; d++) {
			memset(g, 0, sizeof g);
			for (int i = 0; i < d; i++) {
				int j = (i + 1) % d;
				int u = a[i], v = a[j];
				if (u > v) swap(u, v);
				g[u][v] = true;
			}
			for (int i = 0; i < n - d; i++) {
				int j = (i + 1) % (n - d) + d;
				int u = a[i + d], v = a[j];
				if (u > v) swap(u, v);
				g[u][v] = true;
			}
			int c0 = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (g[i][j] != f[i][j]) c0++;
				}
			}
			ans = min(ans, c0);
		}
	} while (next_permutation(a.begin(), a.end()));
	cout << ans << endl;
	return 0;
}