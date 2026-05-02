#include <bits/stdc++.h>
using namespace std;
#define int long long
int s, a, b, x;
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

}
void solve() {
	cin >> s >> a >> b >> x;
	int ans = 0;
	while (x) {
		int run = min(x, a);
		x -= run;
		ans += run * s;
		int sleep = min(x, b);
		x -= sleep;
	}
	cout << ans << endl;
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
