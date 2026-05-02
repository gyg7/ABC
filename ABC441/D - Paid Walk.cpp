#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, l, s, t;
struct edge {
	int nxt, to, val;
} e[N];
int head[N], tot;
bool ansd[N];
struct node {
	int u, dist, cost;
};
queue<node> que;
int main() {
	cin >> n >> m >> l >> s >> t;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[++tot].nxt = head[u];
		e[head[u] = tot].to = v;
		e[tot].val = w;
	}
	que.push((node) {
		1, 0, 0
	});
	while (que.size()) {
		node u = que.front();
		que.pop();
		if (u.dist > l || u.cost > t) continue;
		if (u.dist == l && s <= u.cost) {
			ansd[u.u] = 1;
			continue;
		}
		for (int i = head[u.u]; i; i = e[i].nxt) {
			que.push((node) {
				e[i].to, u.dist + 1, u.cost + e[i].val
			});
		}
	}
	for (int i = 1; i <= n; i++)
		if (ansd[i]) cout << i << " ";

}