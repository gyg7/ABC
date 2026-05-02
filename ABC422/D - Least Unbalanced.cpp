#include <bits/stdc++.h>
using namespace std;
#define int long long
int T = 1, mx, mn = 0x3f3f3f3f3f3f3f3f;
void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a{k};
	for (int i = 1; i <= n; i++) {
		vector<int> b;
		for (int v : a) {
			b.push_back(v / 2);
			b.push_back(v - v / 2);
		}
		a = b;
	}
	for (int v : a) {
		mx = max(mx, v);
		mn = min(mn, v);
	}
	cout << mx - mn << endl;
	for (int v : a) cout << v << " ";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	//cin >> T;
	while (T--) solve();
	return 0;
}


