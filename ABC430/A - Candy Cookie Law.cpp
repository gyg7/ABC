#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b, c, d;
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
	cin >> a >> b >> c >> d;
}
void solve() {
	if (c < a) cout << "No" << endl;
	else if (c >= a && d >= b)
		cout << "No" << endl;
	else cout << "Yes" << endl;
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
