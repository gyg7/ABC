#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
typedef modint998244353 mint;
const int N = 1e6+10;
int n, p[N], c[N], d[N];
int sc[N], sd[N];
vector<int> ve[N];
mint dp[N];
mint C(int n, int m) {
	mint res = 1;
	for (int i = 1; i <= m; i++)
		res = res * (n - i + 1) / i;
	return res;
}
void solve(int u) {
	sc[u] = c[u];
	sd[u] = d[u];
	for (int v : ve[u]) {
		solve(v);
		sc[u] += sc[v];
		sd[u] += sd[v];
	}
}
mint dfs1(int u) {
	mint res = C(sc[u] - sd[u] + d[u], d[u]);
	for (int v : ve[u]) {
		res *= dfs1(v);
	}
	return res;
}
int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		ve[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
	solve(1);
	cout << dfs1(1).val() << endl;
}
