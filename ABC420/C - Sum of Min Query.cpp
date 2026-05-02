#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
const int N = 2e5 + 1;
int t = 1;
int n, q, a[N], b[N], sum;
void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
		sum += min(a[i], b[i]);
	for (int i = 1; i <= q; i++) {
		char c;
		int x, v;
		cin >> c >> x >> v;
		if (c == 'A') {
			sum -= min(a[x], b[x]);
			a[x] = v;
			sum += min(a[x], b[x]);
			cout << sum << endl;
		}
		if (c == 'B') {
			sum -= min(a[x], b[x]);
			b[x] = v;
			sum += min(a[x], b[x]);
			cout << sum << endl;
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


