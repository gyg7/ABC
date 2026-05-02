#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200001], b[200001], s[200001], s2[200001];
long long ans;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	sort(a + 1, a + 1 + n, greater<long long>());
	sort(b + 1, b + 1 + m, greater<long long>());
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
		ans = max(ans, s[i]);
	}
	for (int i = 1; i <= m; i++) s2[i] = s2[i - 1] + b[i];
	for (int i = 1; i <= n; i++) {
		int l = 1, r = min(m, i), idx = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (b[mid] > 0) {
				idx = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
		ans = max(ans, s[i] + s2[idx]);
	}
	cout << ans << endl;
	return 0;
}