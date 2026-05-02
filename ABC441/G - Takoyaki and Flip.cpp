#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
struct val {
	int mx, cnt, len;
	val() {}
	val(int a, int b, int c): mx(a), cnt(b), len(c) {}
	val operator +(const val &b) const {
		val res;
		res.mx = max(mx, b.mx);
		res.cnt = cnt + b.cnt;
		res.len = len + b.len;
		return res;
	}
};
struct tag {
	int clear, zero, va;
	tag() {}
	tag(int a, int b, int c): clear(a), zero(b), va(c) {}
	tag operator +(const tag &b) const {
		tag res;
		res.clear = clear | b.clear;
		res.zero = zero ^ b.zero;
		if (b.clear) res.va = b.va;
		else res.va = va + b.va;
		return res;
	}
};
struct node {
	int ls, rs;
	val v;
	tag tg;
	void upd(tag t) {
		if (t.clear) {
			v.mx = 0;
			if (t.zero)
				v.cnt = v.len - v.cnt;
			if (v.cnt)
				v.mx = t.va;
		} else {
			if (v.cnt) {
				v.mx += t.va;
			}
		}
		tg = tg + t;
	}
} tr[2 * N];
int tot;
int build(int pl, int pr) {
	int o = ++tot;
	if (pl == pr) {
		tr[o].v = val(0, 1, 1);
		return o;
	}
	int mid = (pl + pr) / 2;
	tr[o].ls = build(pl, mid);
	tr[o].rs = build(mid + 1, pr);
	tr[o].v = tr[tr[o].ls].v + tr[tr[o].rs].v;
	return o;
}
void pushdown(int p) {
	tr[tr[p].ls].upd(tr[p].tg);
	tr[tr[p].rs].upd(tr[p].tg);
	tr[p].tg = tag(0, 0, 0);
}
void update(int p, int pl, int pr, int L, int R, tag t) {
	if (L <= pl && pr <= R) return tr[p].upd(t);
	pushdown(p);
	int mid = (pl + pr) / 2;
	if (L <= mid) update(tr[p].ls, pl, mid, L, R, t);
	if (mid < R) update(tr[p].rs, mid + 1, pr, L, R, t);
	tr[p].v = tr[tr[p].ls].v + tr[tr[p].rs].v;
}
val query(int p, int pl, int pr, int L, int R) {
	if (L <= pl && pr <= R) return tr[p].v;
	pushdown(p);
	int mid = (pl + pr) / 2;
	if (R <= mid) return query(tr[p].ls, pl, mid, L, R);
	if (mid < L) return query(tr[p].rs, mid + 1, pr, L, R);
	return query(tr[p].ls, pl, mid, L, R) + query(tr[p].rs, mid + 1, pr, L, R);

}
int n, q, t, l, r, x;
signed main() {
	cin >> n >> q;
	build(1, n);
	for (int i = 1; i <= q; i++) {
		cin >> t >> l >> r;
		if (t == 1) {
			cin >> x;
			tag tg(0, 0, x);
			update(1, 1, n, l, r, tg);
		} else if (t == 2) {
			tag tg(1, 1, 0);
			update(1, 1, n, l, r, tg);
		} else cout << query(1, 1, n, l, r).mx << endl;
	}
}