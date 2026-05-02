#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, q, a[N];
int t[N];
int lb(int x) {
	return x & -x;
}
void add(int x, int v) {
	while (x < N) {
		t[x] += v;
		x += lb(x);
	}
}
int sum(int x) {
	int res = 0;
	while (x) {
		res += t[x];
		x -= lb(x);
	}
	return res;
}
int t2[N];
void add2(int x, int v) {
	while (x < N) {
		t2[x] += v;
		x += lb(x);
	}
}
int sum2(int x) {
	int res = 0;
	while (x) {
		res += t2[x];
		x -= lb(x);
	}
	return res;
}
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
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		add(a[i] + 1, 1);
		add2(a[i] + 1, a[i]);
	}

}
void solve() {
	for (int i = 1; i <= q; i++) {
		int opt, l, r;
		cin >> opt >> l >> r;
		if (opt == 1) {
			add(a[l] + 1, -1);
			add(r + 1, 1);
			add2(a[l] + 1, -a[l]);
			add2(r + 1, r);
			a[l] = r;
		} else {
			if (l < r) {
				int suml = sum(l), sumr = sum(N - 1) - sum(r + 1);
				int sumcnt = sum2(r + 1) - sum2(l);
				cout << sumcnt + suml*l + sumr*r << endl;
			} else cout << l*n << endl;
		}
	}
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
	return 0;
}
