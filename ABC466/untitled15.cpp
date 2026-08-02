#include <bits/stdc++.h>
using namespace std;
int n, m;
struct edge {
	int nxt, to, val;
} e[40];
int head[10], cur, dist[10], cnt[10];
bool vis[10];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int r, l, s;
		cin >> l >> r >> s;

		e[++cur] = {head[l - 1], r, s};
		head[l - 1] = cur;
		e[++cur] = {head[r], l - 1, -s};
		head[r] = cur;
	}
	// sm[r]=s+sm[l-1]
	// dist[v]=dist[u]+s
	queue<int> que;
	for (int i = 0; i <= n; i++) {
		dist[i] = 0;
		vis[i] = 1;
		que.push(i);
	}

	while (que.size()) {
		int u = que.front();
		que.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to, w = e[i].val;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				if (vis[v] == 0) {
					vis[v] = 1;
					que.push(v);
					if (cnt[v] > n) {
						cout << "Infinity" << endl;
						return 0;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << endl;
	}
	return 0;
}
