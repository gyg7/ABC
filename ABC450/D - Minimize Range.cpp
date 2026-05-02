#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, k, ans, a[N];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] %= k;
	}
	sort(a + 1, a + 1 + n);
	ans = a[n]- a[1];
	for (int i = 1; i < n; i++)
		ans = min(ans, a[i] + k - a[i + 1]);
	cout << ans << endl;
}
