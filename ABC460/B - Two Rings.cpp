#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t;
	cin >> t;
	while (t--) {
		ll x0, y0, r0, x1, y1, r1;
		cin >> x0 >> y0 >> r0 >> x1 >> y1 >> r1;

		ll dx = x0 - x1;
		ll dy = y0 - y1;
		ll d2 = dx * dx + dy * dy;      // 圆心距的平方
		ll sum_r = r0 + r1;
		ll sum_r2 = sum_r * sum_r;      // (r0+r1)²

		if (d2 <= sum_r2) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
