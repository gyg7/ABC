#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, u, v;
vector<int> ve[11];
void pre() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
}
void clear() {

}
void readmeta() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		ve[u - 1].push_back(v - 1);
	}
}
void solve() {
	int ans = m;
	for (int i = 0; i < (1 << n); i++) {
		int cnt = 0;
		for (int u = 0; u < n; u++)
			for (int v : ve[u])
				if (((i >> u) & 1) == ((i >> v) & 1)) ++cnt;
		ans = min(ans, cnt);
	}
	cout << ans << endl;
}
signed main() {
	pre();
	int t = 1;
//	cin >> t;
	while (t--) {
		clear();
		readmeta();
		solve();

	}
}
