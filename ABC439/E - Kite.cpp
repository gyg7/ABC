#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, ans, d[N];
struct node {
	int a, b;
} p[N];
struct treenode {
	int ls, rs;
	int max;
} tr[N * 200];
int tot, root[N];
int query(int p, int pl, int pr, int L, int R) {
	if (p == 0) return 0;
	if (L <= pl && pr <= R) return tr[p].max;
	int mid = (pl + pr) / 2;
	int res = 0;
	if (L <= mid) res = max(res, query(tr[p].ls, pl, mid, L, R));
	if (mid < R) res = max(res, query(tr[p].rs, mid + 1, pr, L, R));
	return res;
}
void update(int &p, int pl, int pr, int x, int v) {
	int o = ++tot;
	tr[o] = tr[p];
	p = o;
	if (pl == pr) {
		tr[p].max = v;
		return;
	}
	int mid = (pl + pr) / 2;
	if (x <= mid) update(tr[p].ls, pl, mid, x, v);
	if (mid < x) update(tr[p].rs, mid + 1, pr, x, v);
	tr[p].max = max(tr[tr[p].ls].max, tr[tr[p].rs].max);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].a >> p[i].b;
		d[i] = p[i].b;
	}
	sort(p + 1, p + 1 + n, [](node a, node b) {
		if (a.a != b.a) return a.a < b.a;
		return a.b < b.b;
	});
	sort(d + 1, d + 1 + n);
	int m = unique(d + 1, d + 1 + n) - d;
	for (int i = 1; i <= n; i++)
		p[i].b = lower_bound(d + 1, d + 1 + m, p[i].b) - d;
	int j = 0;
	for (int i = 1; i <= n; i++) {
		while (p[j].a < p[i].a) j++;
		int v = query(root[j - 1], 0, m, 0, p[i].b - 1);
		root[i] = root[i - 1];
		update(root[i], 0, m, p[i].b, v + 1);
		ans = max(ans, v + 1);
	}
	cout << ans << endl;
}