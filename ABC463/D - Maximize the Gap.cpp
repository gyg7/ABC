#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, k;
pii ran[200010];
bool cmp(int x) {
	int cnt = 0, r = -x;
	for (int i = 1; i <= n; i++) {
		auto [L, R] = ran[i];
		if (L - r  >= x) {
			++cnt;
			r = R;
			if (cnt >= k) return true;
		}
	}
	return false;
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> ran[i].first >> ran[i].second;
	}
	sort(ran + 1, ran + 1 + n, [](pii a, pii b) {
		return a.second < b.second;
	});
	int l = 1, r = 1e9, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (cmp(mid)) {
			l = mid + 1;
			ans = mid;
		} else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}