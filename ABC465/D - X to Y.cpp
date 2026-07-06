#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		long long x, y, k;
		cin >> x >> y >> k;
		int ans = 0;
		while (x != y) {
			if (x < y) swap(x, y);
			x /= k;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}