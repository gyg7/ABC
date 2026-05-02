#include <bits/stdc++.h>
using namespace std;
#define int long long
const int man = 5e5 + 1;
int n, a[man], b[man], cnt, tree[man], ans;
void add(int x, int v) {
	while (x <= cnt) {
		tree[x] += v;
		x += (x & -x);
	}
}
int sum(int x) {
	int res = 0;
	while (x) {
		res += tree[x];
		x -= (x & -x);
	}
	return res;
}
signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	cnt = unique(b + 1, b + 1 + n) - (b + 1);
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(b + 1, b + 1 + cnt, a[i]) - b;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = cnt, idx = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (2 * b[mid] <= b[a[i]]) {
				idx = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
		ans += sum(idx);
		add(a[i], 1);
	}
	cout << ans << endl;
}