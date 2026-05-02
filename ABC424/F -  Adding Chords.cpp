#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, q, a, b;
int lb(int x) {
	return x & -x;
}
int tree[1000001];
void upd(int x, int v) {
	while (x <= n) {
		tree[x] ^= v;
		x += lb(x);
	}
}
int sum(int x) {
	int res = 0;
	while (x) {
		res ^= tree[x];
		x -= lb(x);
	}
	return res;
}
mt19937_64 rng{chrono::steady_clock::now().time_since_epoch().count()};
void solve() {
	cin >> n >> q;
	for (int i = 1; i <= q; i++) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		if ((sum(b)^sum(a)) == 0) {
			cout << "Yes" << endl;
			int k = rng();
			upd(a, k), upd(b, k);
		} else cout << "No" << endl;
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	int T = 1;
	//cin >> T;
	while (T--) solve();
	return 0;
}