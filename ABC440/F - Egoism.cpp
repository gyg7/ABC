#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 1000000;
typedef long long ll;
#define int long long
int n, q, a[N], b[N], w, x, y;
ll sum;
int k;
namespace segtree {
	struct node {
		int ls, rs, num, sum, cnt;
	} tr[M << 1];
	int tot;
	int build(int pl, int pr) {
		int o = ++tot;
		if (pl == pr) return o;
		int mid = (pl + pr) / 2;
		tr[o].ls = build(pl, mid);
		tr[o].rs = build(mid + 1, pr);
		return o;
	}
	void add(int o, int pl, int pr, int x, int y, int z, int t) {
		if (pl == pr) {
			tr[o].num += y;
			tr[o].sum += z;
			tr[o].cnt += t;
			return;
		}
		int mid = (pl + pr) / 2;
		if (x <= mid) add(tr[o].ls, pl, mid, x, y, z, t);
		else add(tr[o].rs, mid + 1, pr, x, y, z, t);
		tr[o].num = tr[tr[o].ls].num + tr[tr[o].rs].num;
		tr[o].sum = tr[tr[o].ls].sum + tr[tr[o].rs].sum;
		tr[o].cnt = tr[tr[o].ls].cnt + tr[tr[o].rs].cnt;
	}
	ll querysum(int o, int pl, int pr, int x) {
		if (x == 0) return 0;
		if (pl == pr) return tr[o].sum / tr[o].num * x;
		int rnum = tr[tr[o].rs].num, mid = (pl + pr) / 2;
		if (x <= rnum) {
			return querysum(tr[o].rs, mid + 1, pr, x);
		} else {
			return tr[tr[o].rs].sum + querysum(tr[o].ls, pl, mid, x - rnum);
		}
	}
	int querytot(int o, int pl, int pr, int x) {
		if (x == 0) return 0;
		if (pl == pr) return  min(tr[o].cnt, x);
		int rnum = tr[tr[o].rs].num, mid = (pl + pr) / 2;
		if (x <= rnum) {
			return querytot(tr[o].rs, mid + 1, pr, x);
		} else {
			return  tr[tr[o].rs].cnt + querytot(tr[o].ls, pl, mid, x - rnum);
		}
	}
};
multiset<int> se[2];
signed main() {
	cin >> n >> q;
	segtree::build(1, M);
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		sum += a[i];
		segtree::add(1, 1, M, a[i], 1, a[i], b[i] == 2);
		k += (b[i] == 2);
		se[b[i] == 2].insert(a[i]);
	}
	for (int i = 1; i <= q; i++) {
		cin >> w >> x >> y;
		sum = sum - a[w] + x;
		k = k - (b[w] == 2) + (y == 2);
		segtree::add(1, 1, M, a[w], -1, -a[w], -(b[w] == 2));
		se[b[w] == 2].erase(se[b[w] == 2].find(a[w]));
		segtree::add(1, 1, M, x, 1, x, y == 2);
		a[w] = x, b[w] = y;
		se[y == 2].insert(x);
		if (se[0].empty() || (*se[0].rbegin()) < (*se[1].begin()))
			cout << sum + segtree::querysum(1, 1, M, k - 1) + (se[0].empty() ? 0 : *se[0].rbegin()) << endl;
		else cout << sum + segtree::querysum(1, 1, M, k) << endl;

	}
}