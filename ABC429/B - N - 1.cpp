#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[101], s;
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
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
	}
}
void solve() {
	for (int i = 1; i <= n; i++) {
		if (s - a[i] == m) {
			cout << "Yes" << endl;
			return ;
		}
	}
	cout << "No" << endl;
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
