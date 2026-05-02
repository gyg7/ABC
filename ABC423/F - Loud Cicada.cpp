#include <bits/stdc++.h>
using namespace std;
#define int long long
int T = 1;
int n, m, a[31], y;
int f[1 << 20], ans[31];
int gcd(int n, int m) {
	if (m == 0) return n;
	return gcd(m, n % m);
}
void solve() {
	cin >> n >> m >> y;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i < (1 << n); i++) {
		int l = 1;
		for (int j = 1; j <= n; j++) {
			if (i&(1<<(j-1))) {
				if (l / gcd(l, a[j]) <= y/a[j])
					l = l / gcd(l, a[j]) * a[j];
				else {
					l = y + 1;
					break;
				}
			}
		}
		f[i] = y / l;
	}for (int j = 1; j <= n; j++)
	for (int i = 0; i < (1 << n); i++)
		
			if (!(i&(1<<(j-1))))
				f[i] = f[i] - f[i | (1 << (j - 1))];
	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		int p = __builtin_popcount(i);
		if (p == m) ans += f[i];
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