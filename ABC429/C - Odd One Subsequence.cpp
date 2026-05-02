#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, x, cnt[200011];
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
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		cnt[x]++;
	}
}
void solve() {
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += (cnt[i] * (cnt[i] - 1) / 2) * (n - cnt[i]);
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
