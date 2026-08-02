#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b, c;
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
	cin >> a >> b >> c;
}
void solve() {
	if (a < b) swap(a, b);
	if (a < c) swap(a, c);
	if (b < c) swap(b, c);
	cout << a << b << c << endl;
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
