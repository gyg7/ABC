#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;
int n, q, a[maxn], x[maxn], y[maxn];
struct node {
	int ls, rs;
	int min, max;
};
struct tree {
	node tr[2 * maxn];
	int tot;
	void pushup(int p) {
		tr[p].min = min(tr[tr[p].ls].min, tr[tr[p].rs].min);
		tr[p].max = max(tr[tr[p].ls].max, tr[tr[p].rs].max);
	}
	int build(int pl, int pr) {
		int o = ++tot;
		if (pl == pr) {
			tr[o].min = tr[o].max = a[pl];
			return o;
		}
		int mid = (pl + pr) / 2;
		tr[o].ls = build(pl, mid);
		tr[o].rs = build(mid + 1, pr);
		pushup(o);
		return o;
	}
	void update(int p, int pl, int pr, int x, int v) {
		if (pl == pr) {
			tr[p].min = tr[p].max = v;
			return;
		}
		int mid = (pl + pr) / 2;
		if (x <= mid) update(tr[p].ls, pl, mid, x, v);
		else update(tr[p].rs, mid + 1, pr, x, v);
		pushup(p);
	}
	node query(int p, int pl, int pr, int L, int R) {
		if (L <= pl && pr <= R)
			return tr[p];
		int mid = (pl + pr) / 2;
		if (R <= mid) return query(tr[p].ls, pl, mid, L, R);
		else if (mid < L) return query(tr[p].rs, mid + 1, pr, L, R);
		else {
			node lv = query(tr[p].ls, pl, mid, L, R);
			node rv =  query(tr[p].rs, mid + 1, pr, L, R);
			tr[tot + 2] = lv, tr[tot + 3] = rv;
			pushup(tot + 1);
			return tr[tot + 1];
		}
	}
} sx, sy;
signed main() {
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= n; i++)
		a[i] = x[i] + y[i];
	sx.build(1, n);
	sx.tr[sx.tot + 1].ls = sx.tot + 2;
	sx.tr[sx.tot + 1].rs = sx.tot + 3;
	for (int i = 1; i <= n; i++) a[i] = x[i] - y[i];
	sy.build(1, n);
	sy.tr[sy.tot + 1].ls = sy.tot + 2;
	sy.tr[sy.tot + 1].rs = sy.tot + 3;
	for (int i = 1; i <= q; i++) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int p, x, y;
			cin >> p >> x >> y;
			sx.update(1, 1, n, p, x + y);
			sy.update(1, 1, n, p, x - y);
		} else {
			int l, r, x, y;
			cin >> l >> r >> x >> y;
			node xv = sx.query(1, 1, n, l, r);
			node yv = sy.query(1, 1, n, l, r);
			int ans = max({abs((x + y) - xv.min), abs((x + y) - xv.max), abs((x - y) - yv.min), abs((x - y) - yv.max)});
			cout << ans << endl;

		}
	}
}