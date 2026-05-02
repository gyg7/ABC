#include <bits/stdc++.h>
using namespace std;
#define int long long
int T = 1;
int x, c;
void solve() {
	cin >> x >> c;
	int l = 0, r = x / 1000, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		int num = mid * c;
		if (num + mid * 1000 <= x) {
			ans = mid*1000;
			l = mid + 1;
		} else r = mid - 1;
	}
	cout << ans << endl;
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


