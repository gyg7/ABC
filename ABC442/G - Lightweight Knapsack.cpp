#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, vector<pair<ll, ll>>> node;
int n;
ll c;
vector<pair<ll, ll>> ve[4];
node pack(vector<pair<ll, ll>> ve, int r, int n) {
	ll pre_sum = 0, last_num = 0, last_sum = 0;
	vector<pair<ll, ll>> res;
	for (auto [val, num] : ve) {
		if (num <= r) {
			pre_sum += num * val;
			r -= num;
			continue;
		}
		if (r > 0) {
			pre_sum += r * val;
			num -= r;
			r = 0;
		}
		if (last_num > 0) {
			if (last_num + num < n) {
				last_num += num;
				last_sum += num * val;
				continue;
			} else {
				last_sum += (n - last_num) * val;
				res.emplace_back(last_sum, 1);
				num -= (n - last_num);
				last_sum = 0;
				last_num = 0;
			}
		}
		res.emplace_back(val * n, num / n);
		last_num = num % n;
		last_sum = (num % n) * val;
	}
	return make_pair(pre_sum, res);
}
int main() {
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		ll w, v, k;
		cin >> w >> v >> k;
		ve[w].push_back({v, k});
	}
	for (int i = 1; i <= 3; i++) {
		sort(ve[i].begin(), ve[i].end());
		reverse(ve[i].begin(), ve[i].end());
	}
	ll ans = 0;
	for (int r1 = 0; r1 < 6; r1++) {
		auto [pre_sm1, pack1] = pack(ve[1], r1, 6);
		for (int r2 = 0; r2 < 3; r2++) {
			auto [pre_sm2, pack2] = pack(ve[2], r2, 3);
			for (int r3 = 0; r3 < 2; r3++) {
				auto[pre_sm3, pack3] = pack(ve[3], r3, 2);
				int pre_w = r1 + r2 * 2 + r3 * 3;
				if (pre_w > c) continue;
				ll sm = pre_sm1 + pre_sm2 + pre_sm3;
				ll r = (c - pre_w) / 6;
				vector<pair<ll, ll>> pack_all;
				pack_all.insert(pack_all.end(), pack1.begin(), pack1.end());
				pack_all.insert(pack_all.end(), pack2.begin(), pack2.end());
				pack_all.insert(pack_all.end(), pack3.begin(), pack3.end());
				sort(pack_all.begin(), pack_all.end());
				reverse(pack_all.begin(), pack_all.end());
				for (auto [val, num] : pack_all) {
					if (num <= r) {
						sm += val * num;
						r -= num;
					} else {
						sm += r * val;
						break;
					}
				}
				ans = max(ans, sm);
			}
		}
	}
	cout << ans << endl;
}