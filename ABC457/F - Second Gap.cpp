#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
typedef modint998244353 mint;

struct node {
	mint v;
	int cnt0;
	node(mint _v = 1, int _c = 0) : v(_v), cnt0(_c) {}
	node(int x) {
		if (x == 0) v = 1, cnt0 = 1;
		else v = x, cnt0 = 0;
	}
	node(mint x) {
		if (x == 0) v = 1, cnt0 = 1;
		else v = x, cnt0 = 0;
	}
	node operator*(const node& b) const {
		return node(v * b.v, cnt0 + b.cnt0);
	}
	node operator/(const node& b) const {
		return node(v / b.v, cnt0 - b.cnt0);
	}
};

const int N = 2e5 + 5;
node res;
mint ans;
int n, d[N], val[N];
vector<int> g[N];

void dfs(int u) {
	res = res / node(val[u] + 1);
	for (int v : g[u])
		res = res / node(val[v]) * node(val[v] + 1);
	if (res.cnt0 == 0) ans += res.v;
	for (int v : g[u]) {
		dfs(v);
		res = res / node(val[v] + 1) * node(val[v]);
	}
	res = res * node(val[u] + 1);
}

int main() {
	cin >> n;
	res = node(1);
	for (int i = 1; i < n; i++) {
		cin >> d[i];
		g[i + d[i]].push_back(i);
	}
	for (int i = 1; i< n; i++) {
		if (d[i] == d[i + 1])
			val[i] = n - i - 1;
		res = res * node(val[i]);
	}
	dfs(n);
	cout << ans.val() << endl;
}
