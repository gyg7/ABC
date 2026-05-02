#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 1;
int T = 1;
int q, opt, x, y, nxt[N];
void solve() {
	cin >> q;
	nxt[0] = -1;
	for (int i = 1; i <= q; i++) {
		cin >> opt >> x;
		if (opt == 1) {
			nxt[i] = nxt[x];
			nxt[x] = i;
		} else {
			cin >> y;
			int p = x, q = y;
			while (p != -1 && q != -1 && p != y && q != x) {
				p = nxt[p], q = nxt[q];
			}
			if (q == x || p == -1) swap(x, y);
			int ans = 0;
			for (int p = nxt[x]; p != y; p = nxt[p])
				ans += p;
			cout << ans << endl;
			nxt[x] = y;
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
	//cin >> T;
	while (T--) solve();
	return 0;
}


