#include <bits/stdc++.h>
using namespace std;
#define int long long
int t = 1;
int n, m, a[101];
string s[101];
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++) {
		int x = 0, y = 0;
		for (int j = 1; j <= n; j++)
			if (s[j][i] == '0') x++;
			else y++;
		if (x == 0 || y == 0) {
			for (int j = 1; j <= n; j++)
				a[j]++;
		} else if (x < y) {
			for (int j = 1; j <= n; j++)
				if (s[j][i] == '0') a[j]++;
		} else  if (x > y)
			for (int j = 1; j <= n; j++)
				if (s[j][i] == '1') a[j]++;
	}
	int mx = 0;
	for (int i = 1; i <= n; i++)
		mx = max(a[i], mx);
	for (int i = 1; i <= n; i++)
		if (mx == a[i]) cout << i << " ";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	//cin>>t;
	while (t--) solve();
	return 0;
}


