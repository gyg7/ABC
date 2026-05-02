#include <bits/stdc++.h>
using namespace std;
int n, ans, q, t[1001];
int main() {
	cin >> n >> q;
	ans = n;
	for (int i = 1; i <= q; i++)
		cin >> t[i];
	sort(t + 1, t + 1 + q);
	for (int i = 1; i <= q;) {
		int l = 1, r = q, id = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (t[mid] <= t[i]) {
				id = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
		if ((id - i + 1) % 2 == 1) ans--;
		i = id + 1;
	}
	printf("%d", ans);
}