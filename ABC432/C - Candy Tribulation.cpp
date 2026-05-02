#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, x, y, a[200001];

void pre() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
}
void clear() {

}
void readmeta() {
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
void solve() {
	sort(a + 1, a + 1 + n, greater<int>());
	int lim = a[1];
	for (int i = 2; i <= n; i++) {
		if ((a[1] - a[i])*x % (y - x)) {
			puts("-1");
			return;
		}
		int b = (a[1] - a[i]) * x /  (y - x);
		lim = min(lim, a[i] - b);
	}
	if (lim < 0) {
		puts("-1");
		return;
	}
	int ans = lim;
	for (int i = 2; i <= n; i++) {
		int b = (a[1] - a[i]) * x /  (y - x);
		ans += lim + b;
	}
	cout << ans << endl;
}
signed main() {
	pre();
	int t = 1;
//	cin >> t;
	while (t--) {
		clear();
		readmeta();
		solve();
	}
	return 0;
}
