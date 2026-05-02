#include <bits/stdc++.h>
using namespace std;
int n, h, ans;
vector<int> ve[3001];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h;
		ve[h].push_back(i);
	}
	ans = 1;
	for (int in = 1; in <= 3000; in++) {
		if (ve[in].size() == 0) continue;
		int sz = ve[in].size();
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < sz; j++) {
				int pos;
				for (int k = 2; k < 30000; k++) {
					pos = lower_bound(ve[in].begin(), ve[in].end(), ve[in][j] + (k - 1) * i) - ve[in].begin();
					if (ve[in][pos] != ve[in][j] + (k - 1)*i) {
						ans = max(ans, k - 1);
						break;
					}
				}
			}
		}
	}
	cout << ans << endl;
}