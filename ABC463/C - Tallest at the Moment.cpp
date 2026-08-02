#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 3e5+10;
int n, q, mx[N], ans[N];
pii t[N], ask[N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i].first >> t[i].second;
	}
	sort(t + 1, t + 1 + n, [](pii a, pii b) {
		if (a.second != b.second)return a.second < b.second;
		return a.first < b.first;
	});
	for (int i = n; i >= 1; i--) {
		mx[i] = max(mx[i + 1], t[i].first);
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> ask[i].first;
		ask[i].second = i;
	}
	sort(ask + 1, ask + 1 + q);
	for (int i = 1; i <= q; i++) {
		int l = 1, r = n, pos = n;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (ask[i].first < t[mid].second) {
				r = mid - 1;
				pos = mid;
			} else l = mid + 1;
		}
		ans[ask[i].second] = mx[pos];
	}
    for(int i = 1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}