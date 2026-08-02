#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int n;
int op(int a, int b) {
	return max(a, b);
}
int e() {
	return 0;
}
int a[200010];
int main() {
	cin >> n;
	segtree<int, op, e> seg(2 * n);
	vector<pair<int, int>> ve;
	for (int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r;
		if (l > r) swap(l, r);
		ve.push_back({r, l});
	}
	sort(ve.begin(), ve.end());
	for (int i = 0; i < n; i++) {
		auto [r, l] = ve[i];
		a[i] = seg.prod(l, 2 * n) +1;
		seg.set(l, a[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		auto [r, l] = ve[i];
		a[i] += seg.prod(r, 2 * n);
		ans = max(ans, a[i]);
	}
	cout << ans << endl;
	return 0;
}