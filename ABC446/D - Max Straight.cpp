#include <bits/stdc++.h>
using namespace std;
int n, a[200010], d[400010], num;
int f[400010];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[2 * i - 1] = a[i];
		d[2 * i] = a[i] + 1;
	}
	sort(d + 1, d + 1 + 2 * n);
	num = unique(d + 1, d + 1 + 2 * n) - d;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int id = lower_bound(d + 1, d + num + 1, a[i]) - d;
		f[id] = max(f[id - 1] + 1, 1);
		ans = max(ans, f[id]);
	}
	cout << ans << endl;
}