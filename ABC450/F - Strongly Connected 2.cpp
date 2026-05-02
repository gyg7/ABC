#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 2e5 + 10;
struct tree {
	int ls, rs, pl, pr;
	ll sum, tag = 1;
	int mid() const {
		return (pl + pr) / 2;
	}
	int len() const {
		return pr - pl + 1;
	}
	bool inside(int l, int r) const {
		return l <= pl && pr <= r;
	}
	void cover(ll p) {
		sum = (sum * p) % mod;
		tag = (tag * p) % mod;
	}
} tr[2 * N];
int tot;
int build(int pl, int pr) {
	int p = ++tot;
	tr[p].pl = pl, tr[p].pr = pr;
	if (pl == pr) return p;
	tr[p].ls = build(pl, tr[p].mid());
	tr[p].rs = build(tr[p].mid() + 1, pr);
	return p;
}
void push_down(int p) {
	ll &x = tr[p].tag;
	tr[tr[p].ls].cover(x);
	tr[tr[p].rs].cover(x);
	x = 1;
}
void push_up(int p) {
	tr[p].sum = tr[tr[p].ls].sum + tr[tr[p].rs].sum;
}
void update(int p, int x, ll v) {
	if (tr[p].inside(x, x)) {
		tr[p].sum += v;
		tr[p].sum %= mod;
		return;
	}
	push_down(p);
	if (x <= tr[p].mid()) update(tr[p].ls, x, v);
	else update(tr[p].rs, x, v);
	push_up(p);
}
void modfiy(int p, int l, int r, ll v) {
	if (tr[p].inside(l, r)) {
		tr[p].cover(v);
		return;
	}
	push_down(p);
	if (l <= tr[p].mid()) modfiy(tr[p].ls, l, r, v);
	if (tr[p].mid() < r) modfiy(tr[p].rs, l, r, v);
	push_up(p);
}
ll  query(int p, int l, int r) {
	if (tr[p].inside(l, r)) return tr[p].sum;
	push_down(p);
	ll res = 0;
	if (l <= tr[p].mid()) res = (res + query(tr[p].ls, l, r)) % mod;
	if (tr[p].mid() < r) res = (res + query(tr[p].rs, l, r)) % mod;
	return res;
}
int n, m;
pair<int, int> e[N];
int main() {
	cin >> n >> m;
	build(1, n);
	update(1, 1, 1);
	for (int i = 1; i <= m; i++)
		cin >> e[i].first >> e[i].second;
	sort(e + 1, e + 1 + m);
	for (int i = 1; i <= m; i++) {
		auto [x, y] = e[i];
		ll sm = query(1, x, y);
		update(1, y, sm);
		if(x>1)modfiy(1, 1, x - 1, 2);
		if(y<n)modfiy(1, y + 1, n, 2);
	}
	cout << query(1, n, n) << endl;
}