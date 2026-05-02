#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9;
const int N = 1e6 + 10;
int n, k;
struct tree {
	int ls, rs;
	long long sum;
} tr[N << 1];
int tot;
int build(int pl, int pr) {
	int o = ++tot;
	if (pl == pr) {
		if (pl <= k) tr[o].sum = 1;
		return o;
	}
	int mid = (pl + pr) / 2;
	tr[o].ls = build(pl, mid);
	tr[o].rs = build(mid + 1, pr);
	tr[o].sum = (tr[tr[o].ls].sum + tr[tr[o].rs].sum) % mod;
	return o;
}
void change(int p, int pl, int pr, int x, int v) {
	if (pl == pr) {
		tr[p].sum = v;
		return;
	}
	int mid = (pl + pr) / 2;
	if (x <= mid) change(tr[p].ls, pl, mid, x, v);
	else change(tr[p].rs, mid + 1, pr, x, v);
	tr[p].sum = (tr[tr[p].ls].sum + tr[tr[p].rs].sum) % mod;
}
int query(int p, int pl, int pr, int L, int R) {
	if (L <= pl && pr <= R)
		return tr[p].sum;
	int mid = (pl + pr) / 2, res = 0;
	if (L <= mid) res += query(tr[p].ls, pl, mid, L, R);
	if (mid < R) res += query(tr[p].rs, mid + 1, pr, L, R);
	return res % mod;
}
int main() {
	cin >> n >> k;
	build(0, n);
	for (int i = k; i <= n; i++) {
		int val = query(1, 0, n, i - k, i - 1);
		change(1, 0, n, i, val);
	}
	cout << query(1, 0, n, n, n) << endl;
	return 0;
}