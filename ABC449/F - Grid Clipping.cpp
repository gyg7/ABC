#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
#define int long long
int H, W, h, w, N;
struct tree {
	int ls, rs, pl, pr;
	int cnt, len;
	int cover;
	int mid() const {
		return (pl + pr) / 2;
	}
	bool inside(int l, int r) const {
		return l <= pl && pr <= r;
	}
} tr[maxn * 50];
int tot;
void pushup(int p) {
	if (tr[p].cover > 0) tr[p].cnt = tr[p].len;
	else tr[p].cnt = tr[tr[p].ls].cnt + tr[tr[p].rs].cnt;
}
int update(int p, int pl, int pr, int l, int r, int v) {
	if (!p) {
		p = ++tot;
		tr[p].pl = pl;
		tr[p].pr = pr;
		tr[p].len = pr - pl + 1;
	}
	if (tr[p].inside(l, r)) {
		tr[p].cover += v;
		pushup(p);
		return p;
	}
	if (l <= tr[p].mid()) tr[p].ls = update(tr[p].ls, pl, tr[p].mid(), l, r, v);
	if (tr[p].mid() < r) tr[p].rs = update(tr[p].rs, tr[p].mid() + 1, pr, l, r, v);
	pushup(p);
	return p;
}
struct scanline {
	int x, yl, yr, type;
	scanline() {}
	scanline(int x, int yl, int yr, int type): x(x), yl(yl), yr(yr), type(type) {}
} scan[2 * maxn];
bool cmp(scanline a, scanline b) {
	if (a.x != b.x)
		return a.x < b.x;
	return a.type < b.type;
}
signed main() {
	cin >> H >> W >> h >> w >> N;
	for (int i = 1; i <= N; i++) {
		int x, y;
		cin >> x >> y;
		int xt = x - h + 1, xb = x, yl = y - w + 1, yr = y;
		xt = max(xt, 1ll), yl = max(1ll, yl), xb = min(xb, H - h + 1), yr = min(yr, W - w + 1);
		scan[i] = scanline(xt, yl, yr, 1);
		scan[i + N] = scanline(xb+1, yl, yr, -1);
	}
	N <<= 1;
	sort(scan + 1, scan + N + 1, cmp);
	long long ans = (W - w + 1) * (H - h + 1);
	int root = 0;
	for (int i = 1; i < N; i++) {
		root = update(root, 1, W - w + 1, scan[i].yl, scan[i].yr, scan[i].type);
		long long cnt = (scan[i + 1].x - scan[i].x) * tr[root].cnt;
		ans -= cnt;
	}
	cout << ans << endl;
}