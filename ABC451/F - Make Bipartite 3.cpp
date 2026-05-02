#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q, u, v;
int s[N], d[N], sz[N], cnt0[N], cnt1[N];
int find(int x) {
	if (s[x] == x) return x;
	int r = find(s[x]);
	d[x] ^= d[s[x]];
	s[x] = r;
	return r;
}
int ans;
int meger(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) {
		if (d[x] == d[y]) return -1;
		return 0;
	}
	if (sz[fx] < sz[fy]) swap(fx, fy);
	ans -= min(cnt0[fx], cnt1[fx]);
	ans -= min(cnt0[fy], cnt1[fy]);
	s[fy] = fx;
	d[fy] = d[x] ^ d[y] ^ 1;
	sz[fx] += sz[fy];
	if (d[fy] == 0) {
		cnt0[fx] += cnt0[fy];
		cnt1[fx] += cnt1[fy];
	} else {
		cnt0[fx] += cnt1[fy];
		cnt1[fx] += cnt0[fy];
	}
	ans += min(cnt1[fx], cnt0[fx]);
	return 1;

}
int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cnt0[i] = 1;
		s[i] = i;
		sz[i] = 1;
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		int p = meger(x, y);
		if (p != -1) cout << ans << endl;
		else {
			for (int j = i; j <= q; j++) cout << -1 << endl;
			return 0;
		}
	}
	return 0;
}