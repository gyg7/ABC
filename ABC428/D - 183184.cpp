#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, d, pw[20];
int getlog(int x) {
	int res = 0;
	while (x) {
		res++;
		x /= 10;
	}
	return res;
}
int upper(int x) {
	int l = 1, r = 2e9, idx = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (mid * mid >= x) {
			r = mid - 1;
			idx = mid;
		} else l = mid + 1;
	}
	return idx;
}
int lower(int x) {
	int l = 1, r = 2e9, idx = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (mid * mid <= x) {
			l = mid + 1;
			idx = mid;
		} else r = mid - 1;
	}
	return idx;
}
void pre() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	pw[0] = 1;
	for (int i = 1; i <= 19; i++)
		pw[i] = pw[i - 1] * 10;

}
void clear() {

}
void readmeta() {
	cin >> c >> d;
}
void solve() {
	int ans = 0, mink = getlog(c + 1), maxk = getlog(c + d);
	for (int k = mink; k <= maxk; k++) {
		int minx = c * pw[k] + pw[k - 1], maxx = c * pw[k] + pw[k] - 1;
		if (k == mink)
			minx = c * pw[k] + c + 1;
		if (k == maxk) maxx = c * pw[k] + c + d;
		int r = lower(maxx), l = upper(minx);
		if (r == -1 || l == -1) continue;
		ans += r - l + 1;
	}
	cout << ans << endl;
}
signed main() {
	pre();
	int t = 1;
	cin >> t;
	while (t--) {
		clear();
		readmeta();
		solve();

	}
}