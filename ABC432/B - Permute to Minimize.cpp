#include <bits/stdc++.h>
using namespace std;
#define int long long
int x, a[7];
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
	cin >> x;
}
void solve() {
	int len = 0;
	while (x) {
		a[++len] = x % 10;
		x /= 10;
	}
	sort(a + 1, a + 1 + len);
	for (int i = 1; i <= len; i++) {
		if (a[i]) {
			cout << a[i];
			for (int j = 1; j <= len; j++)
				if (i != j) cout << a[j];
			return;
		}
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
