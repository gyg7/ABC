#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k, tot, mx;
string s, d[1001];
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
	cin >> n >> k >> s;
}
void solve() {
	for (int i = 0; i < n - k + 1; i++) {
		int cnt = 0;
		for (int j = 0; j < n - k + 1; j++) {
			bool flag = true;
			for (int p = 0; p < k; p++) {
				if (s[i + p] != s[j + p]) {
					flag = false;
					break;
				}
			}
			if (flag) ++cnt;
		}
		if (cnt > mx) {
			mx = cnt;
			tot = 0;

		}
		if (mx == cnt)
			d[++tot] = s.substr(i, k);
	}
	sort(d + 1, d + 1 + tot);
	tot = unique(d + 1, d + 1 + tot) - (d + 1);
	cout << mx << endl;
	for (int i = 1; i <= tot; i++)
		cout << d[i] << " ";
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
