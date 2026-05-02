#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 1;
int n, m;
string s, t;
struct node {
	int ls, rs;
int lazy;
} tr[N];
int tot;
int build(int pl, int pr) {
	int o = ++tot;
	if (pl == pr) return o;
	int mid = (pl + pr) / 2;
	tr[o].ls = build(pl, mid);
	tr[o].rs = build(mid + 1, pr);
	return o;
}
void pushdown(int p) {
	if (tr[p].lazy) {
		tr[tr[p].ls].lazy ^= 1;
		tr[tr[p].rs].lazy ^= 1;
		tr[p].lazy = 0;
	}
}
void update(int p, int pl, int pr, int L, int R) {
	if (L <= pl && pr <= R) {
		tr[p].lazy ^= 1;
		return;
	}
	pushdown(p);
	int mid = (pl + pr) / 2;
	if (L <= mid) update(tr[p].ls, pl, mid, L, R);
	if (mid < R) update(tr[p].rs, mid + 1, pr, L, R);
}
bool query(int p, int pl, int pr, int x) {
	if (pl == pr) return tr[p].lazy;
	pushdown(p);
	int mid = (pl + pr) / 2;
	if (x <= mid) return query(tr[p].ls, pl, mid, x);
	else return query(tr[p].rs, mid + 1, pr, x);
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s >> t;
	build(1, n);
	for (int i = 1; i <= m; i++) {
		int l, r;
		cin >> l >> r;
		update(1, 1, n, l, r);
	}
	for (int i = 1; i <= n; i++) {
		if (query(1, 1, n, i)) cout << t[i - 1];
		else cout << s[i - 1];
	}
	return 0;
}

