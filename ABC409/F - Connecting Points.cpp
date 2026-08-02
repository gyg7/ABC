#include <bits/stdc++.h>
using namespace std;
int n, q;
struct point {
	int x, y;
} p[3010];
struct Node {
	int u, v, d;
	Node(int u, int v): u(u), v(v) {
		d = abs(p[u].x - p[v].x) + abs(p[u].y - p[v].y);
	}
	bool operator <(const Node &b) const {
		return b.d < d;
	}
};
priority_queue<Node> pq;
int fa[3001];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void meger(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) return;
	fa[fx] = fy;
}
int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].x >> p[i].y;
	}
    for(int i = 1;i<=3000;i++) fa[i]=i;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			pq.push(Node(i, j));
		}
	}
	for (int i = 1; i <= q; i++) {
		int op;
		cin >> op;
		if (op == 1) {
			++n;
			cin >> p[n].x >> p[n].y;
			for (int j = 1; j < n; j++) {
				pq.push(Node(j, n));
			}
		}
		if (op == 2) {
			while (pq.size()&&find(pq.top().u) == find(pq.top().v)) {
		 pq.pop();
			}
			if (pq.empty()) {
				puts("-1");
				continue;
			}
			int k = pq.top().d;
			printf("%d\n", k);
			while (!pq.empty() && pq.top().d == k) {
				meger(pq.top().u, pq.top().v);
				pq.pop();
			}
		}
		if (op == 3) {
			int u, v;
			cin >> u >> v;
			printf(find(u) == find(v) ? "Yes\n" : "No\n");

		}
	}
	return 0;
}