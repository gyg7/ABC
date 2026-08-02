#include <bits/stdc++.h>
using namespace std;
#define int long long
int T = 1;
int n, R, l[2000010], tmp[2000010];
int ans, p, q;
void solve() {
	cin >> n >> R;
	for (int i = 1; i <= n; i++)
		cin >> l[i];
	p = 1, q = n;
	while (p < R + 1 && l[p])++p;
	while (q > R && l[q])--q;
	ans = q - p + 1;
	for (int i = p; i <= q; i++) ans += l[i];
	cout << ans;
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


