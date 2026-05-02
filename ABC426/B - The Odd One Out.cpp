#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[27];
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
	for (auto ch : s)
		a[ch - 'a']++;
	for (int i = 0; i < 27; i++) {
		if (a[i] == 1) {
			cout << (char)('a' + i) << endl;
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
}
