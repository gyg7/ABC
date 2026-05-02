#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, mx[2], cnt[2];
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
	mx[0] = mx[1] = cnt[0] = cnt[1]=0;
}
void readmeta() {
	cin >> n >> s;
}
void solve() {
	int len;
	for (int i = 0; i < n; i += len) {
		len = 0;
		while (i + len < n && s[i] == s[i + len])++len;
		bool is = s[i] == '1';
		cnt[is] += len;
		mx[is] = max(mx[is], len);
	}
	int ans = 2 * n;
	for (int i = 0; i < 2; i++) {
		int val = 2 * (cnt[i] - mx[i]) + cnt[1 - i];
		if (ans > val) ans = val;
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
