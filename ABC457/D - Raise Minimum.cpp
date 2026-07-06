#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
int a[200001];
int need(int x) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int ned = max(0ll,(x - a[i] + i - 1) / i);
		sum += ned;
		if(sum>k) return sum;
	}
	return sum;
}
signed main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 0, r = LLONG_MAX>>1, ans = 0;
	while (l <= r) {
		int x = (l + r) / 2;
		if (need(x) <= k) {
			l = x + 1;
			ans = x;
		} else r = x - 1;
	}
	cout << ans << endl;
}
