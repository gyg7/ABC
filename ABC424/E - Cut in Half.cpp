#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long double f64;
void solve() {
	int n, k, x;
	int a;
	priority_queue<pair<f64, long long>> pq;
	cin >> n >> k >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		pq.emplace(a, 1);
	}
	while (k > 0) {
		auto [v, cnt] = pq.top();
		pq.pop();
		if (k >= cnt) {
			k -= cnt;
			pq.emplace(v / 2, cnt * 2);
		} else {
			pq.emplace(v, cnt - k);
			pq.emplace(v / 2, k * 2);
			break;
		}
	}
	f64 ans = 0;
	while (x) {
		auto [v, cnt] = pq.top();
		pq.pop();
		if (x > cnt) x -= cnt;
		else {
			ans = v;
			break;
		}
	}
	cout << fixed << setprecision(15) << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}