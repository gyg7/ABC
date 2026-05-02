#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
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
}
void solve() {
	for (int i = 1; i <= n; i++) {
		if (i <= m) cout << "OK" << endl;
		else cout << "Too Many Requests" << endl;
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
}
