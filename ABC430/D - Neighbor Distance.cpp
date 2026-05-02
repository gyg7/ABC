#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, x[500001];
set<int> se;
unordered_map<int, int> unmap;
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
	for (int i = 1; i <= n; i++)
		cin >> x[i];
}
void solve() {
	se.insert(0);
	se.insert(x[1]);
	unmap[0] = unmap[x[1]] = x[1];
	int ans = 2 * x[1];
	cout << ans << endl;
	for (int i = 2; i <= n; i++) {
		auto it = se.lower_bound(x[i]);
		vector<int> hit;
		if (it != se.end()) {
			hit.push_back(*it);
		}
		if (it != se.begin()) {
			--it;
			hit.push_back(*it);
		}
		se.insert(x[i]);
		unmap[x[i]] = 0x3f3f3f3f3f3f3f3f;
		for (int nx : hit) {
			ans -= unmap[nx];
			unmap[nx] = min(unmap[nx], abs(nx - x[i]));
			ans += unmap[nx];
			unmap[x[i]] = min(unmap[x[i]], abs(nx - x[i]));
		}
		ans += unmap[x[i]];
		cout << ans << endl;
	}
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
