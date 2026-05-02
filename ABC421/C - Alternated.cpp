#include <bits/stdc++.h>
using namespace std;
#define int long long
int T = 1;
int n, ans1, old, even, ans2;
string s;
void solve() {
	cin >> n >> s;
	for (int i = 0; i <  2 * n; i++) {
		if (s[i] == 'A') {
			ans1 += abs(i - 2 * old);
			ans2 += abs(i - (2 * old + 1));
			old++;
		}
		if (s[i] == 'B') {
			ans1 += abs(i - (2 * even + 1));
			ans2 += abs(i - 2 * even);
			even++;
		}
	}
	cout << min(ans1, ans2) / 2 << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	//cin >> T;
	while (T--) solve();
	return 0;
}


