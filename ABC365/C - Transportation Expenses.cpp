#include <bits/stdc++.h>
using namespace std;
int n, a[200001];
long long m, l, r, mid, ans;
bool check(long long x) {
	long long sum = 0;
	for (int i = 1; i <= n; i++)
		sum += min(a[i] * 1ll, x);
	return sum <= m;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	l = 0, r = m;
	while (l <= r) {
		if (check(mid = (l + r) / 2)) {
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	if (ans == m) {
		printf("infinite");
	} else cout << ans << endl;
}