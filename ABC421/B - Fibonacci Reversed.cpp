#include <bits/stdc++.h>
using namespace std;
#define int long long
int T = 1;
int f(int x) {
	int y = 0;
	while (x) {
		y = y * 10 + x % 10;
		x /= 10;
	}
	return y;
}
int a, b, c;
void solve() {
	cin >> a >> b;
	for (int i = 3; i <= 10; i++) {
		c = f(a + b);
		a = b, b = c;
	}
	cout << c;
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


