#include <bits/stdc++.h>
using namespace std;
unordered_set<int> se[300011];
int r[300011];
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) se[i].clear();
		for (int i = 1; i <= n; i++) {
			cin >> r[i];
			se[r[i]].insert(i);
		}
		long long  ans = 0;
		for (int i = 1; i <= n; i++)
			for (auto &u : se[i]) {
				if (1<=u-1&&r[u - 1] > r[u] + 1) {
					se[r[u - 1]].erase(u - 1);
					ans += r[u - 1] - (r[u] + 1);
					r[u - 1] = r[u] + 1;
					se[r[u - 1]].insert(u - 1);
				}
				if (u+1<=n&&r[u + 1] > r[u] + 1) {
					se[r[u + 1]].erase(u + 1);
					ans += r[u + 1] - (r[u] + 1);
					r[u + 1] = r[u] + 1;
					se[r[u + 1]].insert(u + 1);

				}
			}
		cout << ans << endl;
	}
}