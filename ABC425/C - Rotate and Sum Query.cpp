#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200001;
int n, q, x, l, r;
int offset, sum[N];
void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		sum[i] = sum[i - 1] + x;
	}
	for (int i = 1; i <= q; i++) {
		int opt, c, l, r;
		cin >> opt;
		if (opt == 1) {
			cin >> c;
			(offset += c) %= n;
		} else {
			cin >> l >> r;
			int start = (l + offset - 1) % n + 1, end = (r + offset - 1) % n + 1;
			if (start <= end)
				cout << sum[end] - sum[start - 1] << endl;
			else cout << sum[n] - sum[start - 1] + sum[end] << endl;
		}
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	int t = 1;
//	cin >> t;
	while (t--) solve();
}


