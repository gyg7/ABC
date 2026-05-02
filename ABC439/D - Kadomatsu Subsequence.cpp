#include <bits/stdc++.h>
using namespace std;
int n, a;long long ans;
unordered_map<int, vector<int>> unmap;
vector<int> ve;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		unmap[a].push_back(i);
		if (a % 3 == 0) ve.push_back(a / 3);
		if (a % 5 == 0) ve.push_back(a / 5);
		if (a % 7 == 0) ve.push_back(a / 7);
	}
	sort(ve.begin(), ve.end());
	ve.erase(unique(ve.begin(), ve.end()), ve.end());
	for (int x : ve) {
		auto i = unmap[x * 7];
		auto j = unmap[x * 5];
		auto k = unmap[x * 3];
		for (int idx : j) {
			int cnti = lower_bound(i.begin(), i.end(), idx) - i.begin();
			int cntk = lower_bound(k.begin(), k.end(), idx) - k.begin();
			ans += 1ll*cnti * cntk;
			ans += 1ll*(i.size() - cnti) * (k.size() - cntk);
		}
	}
	cout << ans << endl;
}
