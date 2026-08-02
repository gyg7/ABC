#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
int n, q, m;
ll  x[N], y[N], a[N];
int getid(ll x) {
	return lower_bound(a + 1, a + 1 + n, x) - a;
}
static inline ll read() {
	ll x = 0;
	char ch = getchar();
	while (isdigit(ch) == 0)
		ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}
int main() {
	n = read(), q = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + 1 + n);
	a[n + 1] = 0x3f3f3f3f3f3f3f;
	for (int i = 1; i <= q; i++)
		x[i] = read(), y[i] = read();
	for (int p = 1; p <= q; p++) {
		ll l = x[p], r = x[p] + y[p] + n;
		while (l < r) {
			ll mid = (l + r) / 2;
			int t = upper_bound(a + 1, a + 1 + n, mid) - lower_bound(a + 1, a + 1 + n, x[p]);
			if ((mid - x[p] + 1) - t >= y[p]) {
				r = mid;
			} else l = mid + 1;
		}
		cout << l << endl;
	}
}