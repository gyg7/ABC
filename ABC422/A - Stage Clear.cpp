#include <bits/stdc++.h>
using namespace std;
#define int long long
int T = 1;
void solve() {
	char a, c, b;
	cin >> a >> c >> b;
	if (b == '8') a++, b = '1';
	else b++;
	cout << a << c << b << endl;
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


