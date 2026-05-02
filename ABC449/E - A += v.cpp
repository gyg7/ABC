#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, a[N], q, cnt[N];
struct ask {
	int x, id;
} p[N];
int ans[N];
vector<int> ve[N];
int tree[N];
int lb(int x) {
	return x & -x;
}
void add(int x, int v) {
	while (x <= m) {
		tree[x] += v;
		x += lb(x);
	}
}
int sum(int x) {
	int res = 0;
	while (x) {
		res += tree[x];
		x -= lb(x);
	}
	return res;
}
signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		++cnt[a[i]];
	}
	for (int i = 1; i <= m; i++) {
		ve[cnt[i]].push_back(i);
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> p[i].x;
		p[i].id = i;
	}
	sort(p + 1, p + 1 + q, [](ask a, ask b) {
		return a.x < b.x;
	});
	int lst = 0, oldval = 0, val = 0, tot = 0;
	for (int i = 1; i <= q; i++) {
		if (p[i].x <= n) ans[p[i].id] = a[p[i].x];
		else if (p[i].x > n * m)
			ans[p[i].id] = (p[i].x - n * m - 1) % m + 1;
		else {
			for (; val < p[i].x - n; lst++) {
				int res = tot;
				for (int j : ve[lst]) {
					res++;
					tot++;
					add(j, 1);
				}
				oldval = val;
				val = val + res;
			}
			int kth = p[i].x - n - oldval, l = 1, r = m, res = 0;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (sum(mid) >= kth) {
					res = mid;
					r = mid - 1;
				} else l = mid + 1;
			}
			ans[p[i].id] = res;
		}
	}
	for (int i = 1; i <= q; i++)
		cout << ans[i] << endl;
}