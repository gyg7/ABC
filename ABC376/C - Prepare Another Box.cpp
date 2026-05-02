#include <bits/stdc++.h>
using namespace std;
int n, a[200001], b[200001];
bool cmp(int x) {
	int j = 1, f = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= b[j] && b[j] <= x) j++;
		else if (a[i] <= x && b[j] > x && f == 0)
			f = 1;
		else if (a[i] <= b[j]) j++;
	}
	return j == n;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n - 1; i++)
		cin >> b[i];
	sort(b + 1, b + n);
	b[n] = 0x3f3f3f3f;
	int l = 1, r = 1000000000, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (cmp(mid)) {
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	cout << ans << endl;
}