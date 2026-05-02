#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n, m;
	cin >> n >> m;
	vector<long long> ve(n), e, suf;
	for (auto &x : ve) cin >> x;
	int lst = 0;
	for (int i = 0; i < n - i - 1; i++) {
		int v = (ve[n - i - 1] - ve[i] + m) % m;
		e.push_back((v - lst + m) % m);
		lst = v;
	}
	e.push_back((m - lst) % m);
	sort(e.begin(), e.end());
	suf.assign(e.size() + 1, 0);
	for (int i = e.size() - 1; i >= 0; i--) {
		suf[i] = suf[i + 1] + (m - e[i]);
	}
	long long ans = 1e18, sm = 0;
	for (int i = 0; i < e.size(); i++) {
		sm += e[i];
		ans = min(ans, max(suf[i + 1], sm));
	}
	cout << ans << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}