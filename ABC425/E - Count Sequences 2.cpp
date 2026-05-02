#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, c[5001], s[5001], C[5010][5010], m;
void pre() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	C[0][0] = C[1][0] = C[1][1] = 1;
	for (int i = 2; i <= 5000; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % m;
	}
}

void clear() {

}
void readmeta() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		s[i] = s[i - 1] + c[i];
	}
	int ans = 1;
	for (int i = 1; i <= n; i++)
		ans = (ans * C[s[n] - s[i-1]][c[i]]) % m;
	cout << ans << endl;
}
void solve() {

}
signed main() {
	int t = 1;
	cin >> t >> m;
	pre();
	while (t--) {
		clear();
		readmeta();
		solve();

	}
}
