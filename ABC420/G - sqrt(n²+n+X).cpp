#include <bits/stdc++.h>
using namespace std;
#define int long long
int T = 1;
int x, y;
int ans[100001], cnt;
void push(int d) {
	ans[++cnt] = (d - y / d - 2) / 4;
}
void solve() {
	cin >> x;
	y = 4 * x - 1;
	for (int p = 1; p <= abs(y) / p; p++) {
		if (y % p == 0) {
			push(p);
			push(-p);
			push(y / p);
			push(-y / p);
		}
	}
	sort(ans + 1, ans + 1 + cnt);
	cnt = unique(ans + 1, ans + 1 + cnt) - (ans + 1);
	cout << cnt << endl;
	for (int i = 1; i <= cnt; i++)
		cout << ans[i] << " ";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	//cin>>T;
	while (T--) solve();
	return 0;
}


