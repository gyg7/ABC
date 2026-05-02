#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, c;
int a[500001], nxt[500001];
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
	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = n; i >= 1; i--) {
		if (i == n || a[i] != a[i + 1]) nxt[i] = i;
		else nxt[i] = nxt[i + 1];
	}
}
void solve() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int j = (i + c - 2) % n + 1;
		ans += (i == 1 ? a[1] + m - a[n] : a[i] - a[i - 1]) * (c + nxt[j] - j);
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
