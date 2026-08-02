#include <bits/stdc++.h>
using namespace std;
#define int long long
int T = 1;
int n, m, k, mp[11], a, b;
void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		cin >> a >> b;
		if (++mp[a] == m)
			cout << a << " ";
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