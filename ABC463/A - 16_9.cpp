#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
const int N = 400005;
typedef modint998244353 mint;
int n, a[N];
mint ans[N], fac[N], invn[N], ipw[N];
mint ksm(mint a, int b) {
	mint res = 1;
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
mint C(int n, int m) {
	if (m < 0 || m > n) return 0;
	return fac[n] / (fac[m] * fac[n - m]);
}
mint F(int c, int p) {
	if (p < 0) return 0;
	mint res = 0;
	for (int i = 0; i <= p; i++) {
		res = (res + C(p, i) * ipw[p] / (c + i));
	}
	return res;
}
void add(int x, mint v) {
	ans[x] += v;
}
int main() {
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> a[i];
	}
	fac[0] = ipw[0] = 1;
	mint inv2 = 998244354 / 2;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
		ipw[i] = ipw[i - 1] * inv2;
	}
	int mx = max(a[1], a[2]);
	int b = 0, s = 0;
	for (int i = 1; i <= n; i++) {
		int x = 2 * i - 1, y = 2 * i;
		int c = (a[x] == mx) + (a[y] == mx);
		if (c == 2) ++b;
		if (c == 1) ++s;
	}
	mint f_same = (b ? F(b, s) : 0),
	     f_single = (s ? F(b + 1, s - 1) : 0);
	for (int i = 1; i <= n; i++) {
		int x = 2 * i - 1, y = 2 * i;
		int c = (a[x] == mx) + (a[y] == mx);
		if (c == 2) {
			add(x, inv2 * f_same);
			add(y, inv2 * f_same);
		}
		if (c == 1) {
			if (a[x] == mx)
				add(x, inv2 * f_single);
			else add(y, inv2 * f_single);
		}
	}
	if (!b) {
		int base = 0, p = 0;
		for (int i = 1; i <= n; i++) {
			int x = 2 * i - 1, y = 2 * i;
			int c = (a[x] == mx) + (a[y] == mx);
			int d = (a[x] == mx - 1) + (a[y] == mx - 1);
			if (c == 1) {
				++base;
				if (d == 1)++base;
			} else {
				if (d == 2) ++base;
				if (d == 1)++p;
			}
		}
		mint coef = ipw[s], f0 = F(base, p), f1 = (p ? F(base + 1, p - 1) : 0);
		for (int i = 1; i <= n; i++) {
			int x = 2 * i - 1, y = 2 * i;
			int c = (a[x] == mx) + (a[y] == mx);
			int d = (a[x] == mx - 1) + (a[y] == mx - 1);
			if (c == 1) {
				if (a[x] == mx || a[x] == mx - 1) add(x, coef * f0);
				if (a[y] == mx || a[y] == mx - 1) add(y, coef * f0);
			} else {
				if (d == 2) {
					add(x, coef * inv2 * f0);
					add(y, coef * inv2 * f0);
				}
				if (d == 1) {
					if (a[x] == mx - 1)
						add(x, coef * inv2 * f1);
					else add(y, coef * inv2 * f1);
				}
			}
		}
	}
	for (int i = 1; i <= 2 * n; i++) {
		cout << ans[i].val() << " ";
	}
	return 0;
}
