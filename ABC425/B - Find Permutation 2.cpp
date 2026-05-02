#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, p[11], x, num, a[11], vis[11];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x != -1) {
			if (p[x]) {
				cout << "No" << endl;
				return;
			}
			p[x] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (p[i]) {
			a[p[i]] = i;
			vis[i] = 1;
		}
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= n; i++) {
		if (!a[i]) {
			for (int j = 1; j <= n; j++) {
				if (vis[j]) continue;
				a[i] = j;
				vis[j] = 1;
				break;
			}
		}
		cout << a[i] << " \n"[i == n];
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	int t = 1;
//	cin >> t;
	while (t--) solve();
}


