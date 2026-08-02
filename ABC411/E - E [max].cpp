#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll Inv(ll a) {
	int e = mod - 2;
	ll res = 1;
	while (e) {
		if (e & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		e >>= 1;
	}
	return res;
}
const int N = 100010;
int n, a[N][6], d[6 * N];
int c[N], tot;
ll inv[10];
vector<int> ve[6 * N];
int main() {
	for (int i = 1; i <= 6; i++) {
		inv[i] = Inv(i);
	}
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> a[i][j];
			d[++tot] = a[i][j];
		}
        c[i]=6;
	}
	sort(d + 1, d + 1 + tot);
	tot = unique(d + 1, d + 1 + tot) - (d + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 6; j++) {
			int pos = lower_bound(d + 1, d + 1 + tot, a[i][j]) - d;
			ve[pos].push_back(i);
		}
	}
	ll now = 1, pre = 1, ans = 0;
	for (int i = tot; i >= 1; i--) {
		for (int p : ve[i]) {
			now = 1ll * now * inv[c[p]] % mod;
			--c[p];
			now = 1ll * now * c[p] % mod;
		}
		ll p = (pre - now + mod) % mod;
		(ans += 1ll * p * d[i] % mod) %= mod;
		pre = now;
	}
	cout << ans << endl;
	return 0;
}