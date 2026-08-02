#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, a[200001], cnt0, cnt1, b[200001], c[200001];
void solve() {
	cin >> n;
	cnt0 = cnt1 = 0;
	int num = 0, pnum = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[1]) num++;
		else if (a[i] == -a[1]) pnum++;
	}
	if (num == n || (num + pnum == n && min(num, pnum) == n / 2)) {
		puts("Yes");
		return;
	}
	sort(a + 1, a + 1 + n, [](int x, int y) {
		x = x < 0 ? -x : x;
		y = y < 0 ? -y : y;
		return x < y;
	});
	for (int i = 2; i < n; i++)
		if (a[i - 1]*a[i + 1] != a[i] * a[i]) {
			puts("No");
			return;
		}
	puts("Yes");
}
signed main() {
	cin >> t;
	for (int _ = 1; _ <= t; _++)
		solve();
}