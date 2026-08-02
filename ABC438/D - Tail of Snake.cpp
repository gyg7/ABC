#include <bits/stdc++.h>
using namespace std;
long long n, a[300001], b[300001], c[300001];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) {
		a[i] += a[i - 1];
		b[i] += b[i - 1];
		c[i] += c[i - 1];
	}
	long long mx = a[1] - b[1], ans = 0;
	for (int y = 2; y < n; y++) {
		ans = max(ans, b[y] - c[y] + mx + c[n]);
		mx = max(mx, a[y] - b[y]);
	}
	cout << ans << endl;
}