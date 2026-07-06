#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct Matriy {
	long long a[2][2];
	Matriy operator *(const Matriy &t) const {
		Matriy res;
		for (int i = 0; i <= 1; i++) {
			for (int j = 0; j <= 1; j++) {
				res.a[i][j] = 1e18;
				for (int k = 0; k <= 1; k++)
					res.a[i][j] = min(res.a[i][j], a[i][k] + t.a[k][j]);
			}
		}
		return res;
	}
};
struct tree {
	int ls, rs, pl, pr;
	Matriy m;
	bool inside(int l, int r) {
		return l<= pl && pr <= r;
	}
	int mid() {
		return (pl + pr) / 2;
	}
} tr[N << 1];
int tot, n;
long long a[N];
int build(int pl, int pr) {
	int o = ++tot;
	tr[o].pl = pl;
	tr[o].pr = pr;
	if (pl == pr) {
		tr[o].m.a[0][0] = 1e18;
		tr[o].m.a[0][1] = 0;
		tr[o].m.a[1][0] = tr[o].m.a[1][1] = a[pl];
		return o;
	}
	int mid = (pl + pr) / 2;
	tr[o].ls = build(pl, mid);
	tr[o].rs = build(mid + 1, pr);
	tr[o].m = tr[tr[o].rs].m * tr[tr[o].ls].m;
	return o;
}
Matriy query(int x, int l, int r) {
	if (tr[x].inside(l, r)) return tr[x].m;
	if (r <= tr[x].mid()) return query(tr[x].ls, l, r);
	else if (tr[x].mid() < l) return query(tr[x].rs, l, r);
	else return query(tr[x].rs, l, r) * query(tr[x].ls, l, r);
}
void solve() {
	int k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	tot = 0;
	build(1, n);
	a[0] = 1e18;
	long long ans = 1e18;
	for (int i = 1; i + k - 1 <= n; i++) {
		Matriy tmp  = query(1, i, i+ k - 1);
		ans = min({ans, tmp.a[1][0],
			tmp.a[0][1] + a[i - 1],
			tmp.a[1][1] + a[i - 1]});
	}
	cout << ans << endl;
}

int main() {
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
