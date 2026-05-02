#include <bits/stdc++.h>
using namespace std;
#define int long long
int T = 1;
void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int ans = min({a, c, (a + b + c) / 3});
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	cin >> T;
	while (T--) solve();
	return 0;
}


