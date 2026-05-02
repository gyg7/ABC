#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
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
	cin >> s;
}
void solve() {
	int n = s.length();
	for (int i = 1; i <= n; i++) {
		if (i == (n + 1) / 2) continue;
		cout << s[i - 1];
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
