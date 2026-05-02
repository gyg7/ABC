#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, fa[N], sz[N];
const int mod = 998244353;
typedef long long ll;
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void meger(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (sz[x] < sz[y]) swap(x, y);
	sz[fa[y] = x] += sz[y];
}

int m, u[N], v[N];
ll ksm(ll x, int y) {
	ll res = 1;
	while (y) {
		if (y & 1) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i];
	}
	ll ans = 0;
	int cnt = n;
	for (int i = 1; i <= n; i++) {
		fa[i] = i, sz[i] = 1;
	}
	for (int i = m; i >= 1; i--) {
		int x = find(u[i]), y = find(v[i]);
		if (x == y) continue;
		if (cnt == 2) {
			ans = (ans + ksm(2, i)) % mod;
		} else {
			--cnt;
			meger(x, y);
		}
	}
	cout << ans << endl;
}