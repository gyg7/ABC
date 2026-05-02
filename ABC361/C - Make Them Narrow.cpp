#include <bits/stdc++.h>
using namespace std;
int n, k, a[200001], ans = 0x3f3f3f3f;
int main(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i + (n - k)-1 <= n; i++) {
		int j = i + (n - k)-1;
		ans = min(ans, a[j] - a[i]);
	}
	printf("%d", ans);
	return 0;
}
