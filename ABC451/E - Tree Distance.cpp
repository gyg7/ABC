#include <bits/stdc++.h>
using namespace std;
int n, a[3010][3010], mine[3010], pa[3010], dist[3010];
bool vis[3010];
struct egde {
	int nxt, to, val;
} e[6010];
int head[3010], tot;
void add(int u, int v, int w) {
	e[++tot].nxt = head[u];
	e[head[u] = tot].to = v;
	e[tot].val = w;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			cin >> a[i][j];
			a[j][i] = a[i][j];
		}
	memset(mine, 0x3f, sizeof mine);
	mine[1] = 0;
	for (int i = 1; i <= n; i++) {
		int u = 0;
		for (int j = 1; j <= n; j++) {
			if (vis[j]) continue;
			if (mine[u] > mine[j]) u = j;
		}
		if (pa[u]) {
			add(u, pa[u], a[u][pa[u]]);
			add(pa[u], u, a[u][pa[u]]);
		}
		vis[u] = 1;
		for (int v = 1; v <= n; v++) {
			if (vis[v]) continue;
			if (mine[v] > a[u][v]) {
				mine[v] = a[u][v];
				pa[v] = u;
			}

		}
	}
	for (int i = 1; i <= n; i++) {
		memset(dist, -1, sizeof dist);
		queue<int> que;
		que.push(i);
		dist[i] = 0;
		while (que.size()) {
			int u = que.front();
			que.pop();
			for (int j = head[u]; j; j = e[j].nxt) {
				int v = e[j].to;
				if (dist[v] == -1) {
					dist[v] = dist[u] + e[j].val;
					que.push(v);
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			if (a[i][j] != dist[j]) {
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	return 0;
}