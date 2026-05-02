#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct tree {
	int ls, rs;
	long long sum;
} tr[N * 30];
int tot, root[N];
int copy(int p) {
	int o = ++tot;
	tr[o] = tr[p];
	return o;
}
int update(int p, int pl, int pr, int x, int v) {
	int o = copy(p);
	if (pl == pr) {
		tr[o].sum = v;
		return o;
	}
	int mid = (pl + pr) / 2;
	if (x <= mid) tr[o].ls = update(tr[o].ls, pl, mid, x, v);
	else tr[o].rs = update(tr[o].rs, mid + 1, pr, x, v);
	tr[o].sum = tr[tr[o].ls].sum + tr[tr[o].rs].sum;
	return o;
}
long long query(int p, int pl, int pr, int L, int R) {
	if (!p) return 0;
	if (L <= pl && pr <= R) return tr[p].sum;
	long long res = 0, mid  = (pl + pr) / 2;
	if (L <= mid) res += query(tr[p].ls, pl, mid, L, R);
	if (mid < R) res += query(tr[p].rs, mid + 1, pr, L, R);
	return res;
}
int main() {
	int n, m, q;
	cin>>n>>m>>q;
	for (int i = 1; i <= q; i++) {
		int opt, x, y, z, l, r;
		cin >> opt >> x;
		if (opt == 1) {
			cin  >> y;
			root[x] = root[y];
		} else if (opt == 2) {
			cin >> y >> z;
			root[x] = update(root[x], 1, m, y, z);
		} else {
			cin >> l >> r;
			cout << query(root[x], 1, m, l, r)<<endl;
		}
	}
}