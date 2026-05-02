#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q, a[N];
int opt, x, l, r;
int lb(int x) {
	return x & -x;
}
void add(int x, int v) {
	while (x < N) {
		a[x] += v;
		x += lb(x);
	}
}
int sum(int x) {
	int res = 0;
	while (x) {
		res += a[x];
		x -= lb(x);
	}
	return res;
}
int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		add(i, x);
	}
	for (int i = 1; i <= q; i++) {
		cin >> opt;
		if (opt == 1) {
			cin >> x;
			int a = sum(x) - sum(x - 1), b = sum(x + 1) - sum(x);
			add(x, -a + b);
			add(x + 1, -b + a);
		}
		if (opt == 2) {
			cin >> l >> r;
			cout << sum(r) - sum(l - 1) << endl;
		}
	}
}