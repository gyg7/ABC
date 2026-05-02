#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 1;
int t = 1;
int n, q, opt, u, v;
int fa[N], sz[N], cnt[N], col[N];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void meger(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (sz[x] < sz[y]) swap(x, y);
	fa[y] = x;
	sz[x] += sz[y];
	cnt[x] += cnt[y];
}
void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		sz[fa[i] = i] = 1;
	for (int i = 1; i <= q; i++) {
		cin >> opt;
		if (opt == 1) {
			cin >> u >> v;
			meger(u, v);
		} else if (opt == 2) {
			cin >> v;
			if (col[v] == 0) {
				cnt[find(v)]++;
				col[v] = 1;
			} else {
				cnt[find(v)]--;
				col[v] = 0;
			}
		} else if (opt == 3) {
			cin >> v;
			if (cnt[find(v)]) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	//cin>>t;
	while (t--) solve();
	return 0;
}


