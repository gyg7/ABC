#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, f[110], a[110], s[110];
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
}
void solve() {
	a[0] = 1;
	f[0] = 1;
	s[0] = 1;
	for (int i = 1; i <= n; i++) {
		a[i] = s[i - 1];
		if (i == n) break;
		while (a[i]) {
			f[i] += a[i] % 10;
			a[i] /= 10;
		}
		s[i] = s[i - 1] + f[i];
	}
	cout << a[n] << endl;
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
}
