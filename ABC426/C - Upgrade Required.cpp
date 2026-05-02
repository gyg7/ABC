#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000000;
int n, q, a[N];
struct tree {
	int ls, rs, sz;
	bool tag;
} tr[2 * N];
int tot;
void push_down(int p) {
	if (tr[p].tag) {
		tr[tr[p].ls].sz = 0;
		tr[tr[p].ls].tag = 1;
		tr[tr[p].rs].sz = 0;
		tr[tr[p].rs].tag = 1;
	}
	tr[p].tag = 0;
}
void pushup(int p) {
	tr[p].sz = tr[tr[p].ls].sz + tr[tr[p].rs].sz;
}
int build(int pl, int pr) {
	int o = ++tot;
	if (pl == pr) {
		tr[o].sz = 1;
		return o;
	}
	int mid = (pl + pr) / 2;
	tr[o].ls = build(pl, mid);
	tr[o].rs = build(mid + 1, pr);
	pushup(o);
	return o;
}
void update1(int p, int pl, int pr, int x) {
	if (pr <= x) {
		tr[p].tag = 1;
		tr[p].sz = 0;
		return;
	}
	push_down(p);
	int mid = (pl + pr) / 2;
	update1(tr[p].ls, pl, mid, x);
	if (mid < x) update1(tr[p].rs, mid + 1, pr, x);
	pushup(p);
}
void update2(int p, int pl, int pr, int x, int v) {
	if (pl == pr) {
		tr[p].sz += v;
		return;
	}
	push_down(p);
	int mid = (pl + pr) / 2;
	if (x <= mid)
		update2(tr[p].ls, pl, mid, x, v);
	else
		update2(tr[p].rs, mid + 1, pr, x, v);
	pushup(p);
}
int query(int p, int pl, int pr, int x) {
	if (pr <= x) return tr[p].sz;
	int res = 0, mid = (pl + pr) / 2;
	push_down(p);
	res = query(tr[p].ls, pl, mid, x);
	if (mid < x) res += query(tr[p].rs, mid + 1, pr, x);
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
	build(1, n);
}
void solve() {
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		int ans = query(1, 1, n, x);
		cout << ans << endl;
		update1(1, 1, n, x);
		update2(1, 1, n, y, ans);
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
}
