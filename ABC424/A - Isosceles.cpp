#include <bits/stdc++.h>
using namespace std;
#define int long long
int T = 1;
int a, b, c;
void solve() {
	cin >> a >> b >> c;
	if (a == b || a == c || b == c) puts("Yes");
	else puts("No");
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