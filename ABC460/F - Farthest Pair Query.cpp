#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
#define N 100010

int dep[N], fa[N][20], n, q;
vector<int> ve[N];

void dfs(int u) {
	dep[u] = dep[fa[u][0]] + 1;
	for (int v : ve[u]) {
		if (fa[u][0] == v) continue;
		fa[v][0] = u;
		for (int i = 1; i <= 19; i++)
			fa[v][i] = fa[fa[v][i - 1]][i - 1];
		dfs(v);
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 19; i >= 0; i--) {
		if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if (x == y) return x;
	for (int i = 19; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) {
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}

struct Node {
	int x, y;
	int dist;

	Node(): x(0), y(0), dist(-1e9) {}

	Node(int x, int y): x(x), y(y) {
		dist = dep[x] + dep[y] - 2 * dep[lca(x, y)];  // ✅ 修正：+ 而非 -
	}

	bool operator<(const Node& b) const {
		return dist < b.dist;
	}
};

Node merge_node(Node v0, Node v1) {  // ✅ 修正函数名
	Node res = max({v0, v1,
	                Node(v0.x, v1.x), Node(v0.x, v1.y),
	                Node(v0.y, v1.x), Node(v0.y, v1.y)});
	return res;
}

Node e() {  // 单位元
	return Node();
}

int col[N];

// ✅ 修正：补全线段树模板参数

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ve[x].push_back(y);
		ve[y].push_back(x);
	}

	atcoder::segtree<Node, merge_node, e> seg(n);
	dfs(1);
	for (int i = 1; i <= n; i++) {
		col[i] = 1;
		seg.set(i - 1, Node(i, i));
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int x;
		cin >> x;
		if (col[x]) seg.set(x - 1, Node(0, 0));
		else seg.set(x - 1, Node(x, x));
		cout << seg.all_prod().dist << endl;
	}
}
