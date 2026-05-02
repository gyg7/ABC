#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10; 
ll n, a[maxn];
ll m, sm;
bool check(int X) {
	map<int, ll> mp;	ll h = (n + m + 1) / 2;
	int gtx = 0;

	for (int i = 1; i <= n; i++) {
		if (a[i] >= X) {
			gtx++;
			if (a[i] >= 2 * X - 1) {
                int val = a[i];
				ll c0 = 1, c1 = 0;

				for (; val >= 2 * X - 1; val /= 2) {
					if (val & 1) c1 = c1 * 2 + c0;
					else c0 = 2 * c0 + c1;
				}
				if (val >= X) mp[val] += c0;
				if (val + 1 == 2 * X - 1) mp[X] += c1;
				else mp[val + 1] += c1;
			} else  mp[a[i]]++;
		}
	}
	if (gtx + m < h) return false;
	ll rem = h, s = 0;
	for (auto [val, cnt] : mp) {
		if (rem <= cnt) {
			s += rem * val;
			rem = 0;
			break;
		}
		s += val * cnt;
		rem -= cnt;
	}
	if (rem > 0) return false;
	return sm - s >= (n + m - 1) / 2;
}
void slove() {
	scanf("%d%lld", &n, &m);
	sm = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		sm += a[i];
	}
	int l = 1, r = 1e9, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	cout << ans << endl;
}
signed main() {
    int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
		slove();
}