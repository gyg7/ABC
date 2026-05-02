#include <bits/stdc++.h>
using namespace std;
#define int long long
int T = 1;
int n, l[101], L, R;
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> l[i];
	for (int i = 1; i <= n; i++) {
		if (l[i] == 0) L++;
		else break;
	}
	R = n;
	for (int i = n; i >= 1; i--) {
		if (l[i] == 0) R--;
		else break;
	}
	cout << max(0ll, R - (L + 1)) << endl;
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


