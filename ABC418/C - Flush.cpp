#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, q, a[300001], b;
int s[300001];
signed main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= q; i++) {
		cin >> b;
		int l = 1, r = n, ans = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (a[mid] < b) {
				ans = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
		ans = s[ans] + (n - ans) * (b - 1) + 1;
		printf("%lld\n", ans <= s[n] ? ans : -1);
	}
	return 0;
}
