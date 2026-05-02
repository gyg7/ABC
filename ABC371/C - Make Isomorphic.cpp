#include <bits/stdc++.h>
using namespace std;
int n, m, u, v;
long long ans = 0x3f3f3f3f3f3f3f3f;
int a[9][9], b[9][9], c[9][9];
int p[9], vis[9];
void dfs(int cur) {
	if (cur == n + 1) {
		long long sum = 0;
		for (int i = 1; i <= n - 1; i++)
			for (int j = i + 1; j <= n; j++)
				if (b[i][j] && c[p[i]][p[j]] == 0)
					sum += a[p[i]][p[j]];
				else if (b[i][j] == 0 && c[p[i]][p[j]])
					sum += a[p[i]][p[j]];
		if (sum < ans) ans = sum;
		return;
	}
	for (int i = 1; i <= n; i++)
		if (vis[i] == 0) {
			vis[i] = 1;
			p[cur] = i;
			dfs(cur + 1);
			p[cur] = 0;
			vis[i] = 0;
		}

}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		b[u][v] = b[v][u] = 1;
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		c[u][v] = c[v][u] = 1;
	}
	for (int i = 1; i <= n - 1; i++)
		for (int j = i + 1; j <= n; j++) {
			cin >> a[i][j];
			a[j][i]=a[i][j];
		}
	dfs(1);
	printf("%d", ans);
}