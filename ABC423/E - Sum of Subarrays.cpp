#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 1;
int T = 1;
int n, q, l, r,x, s1[N], s2[N], s3[N];
void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		s1[i] = i * i * x;
		s2[i] = i * x;
		s3[i] = x;
	}
	for (int i = 1; i <= n; i++) {
		s1[i] += s1[i - 1];
		s2[i] += s2[i - 1];
		s3[i] += s3[i - 1];
	}
	for (int i = 1; i <= q; i++) {
		cin >> l >> r;
		int a = -1, b = l + r, c = (-l + 1) * (r + 1);
		int val = (s1[r] - s1[l - 1]) * a + (s2[r] - s2[l - 1]) * b + (s3[r] - s3[l - 1])*c;
		cout << val << endl;
	}
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