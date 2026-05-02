#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, opt, x, p, head, tail, root;
struct tree {
	int ls, rs, val, lazy;
	void addtag(int v, int len) {
		val += len * v;
		lazy += v;
	}
} tr[600001];
int tot;
void push_down(int p, int pl, int pr) {
	int &x = tr[p].lazy;
	if (x == 0) return;
	int mid = (pl + pr) / 2;
	tr[tr[p].ls].addtag(x, mid - pl + 1);
	tr[tr[p].rs].addtag(x, pr - mid);
	x = 0;
}
void update(int &o, int pl, int pr, int L, int R, int v) {
	if (o == 0) o = ++tot;
	if (L <= pl && pr <= R) {
		tr[o].addtag(v, pr - pl + 1);
		return ;
	}
	int mid = (pl + pr) / 2;
	push_down(o, pl, pr);
	if (L <= mid) update(tr[o].ls, pl, mid, L, R, v);
	if (mid < R) update(tr[o].rs, mid + 1, pr, L, R, v);
	tr[o].val = tr[tr[o].ls].val + tr[tr[o].rs].val;
}
int query(int o, int pl, int pr, int L, int R) {
	if (o == 0) o = ++tot;
	if (L <= pl && pr <= R)
		return tr[o].val;
	int mid = (pl + pr) / 2, res = 0;
	push_down(o, pl, pr);
	if (L <= mid) res += query(tr[o].ls, pl, mid, L, R);
	if (mid < R) res += query(tr[o].rs, mid + 1, pr, L, R);
	return res;
}
signed main() {
	cin >> n;
	head = 1, tail = 0;
	for (int i = 1; i <= n; i++) {
		cin >> opt;
		if (opt == 1) {
			cin >> x;
			++tail;
			update(root, 1, n, tail, tail, x);
		} else if (opt == 2) {
			p = query(root, 1, n, head, head);
			update(root, 1, n, head, head, -p);
			head++;
		} else {
			cin >> x;
			if (2 <= x)
				cout << query(root, 1, n, head, head + x - 2) << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}