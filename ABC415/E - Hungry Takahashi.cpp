#include <bits/stdc++.h>
using namespace std;
#define int long long
int h, w, a[200001], p[200001], dp[200001];
int idx(int x, int y) {
	return (x - 1) * w + y;
}
signed main() {
	cin >> h >> w;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> a[idx(i, j)];
	for (int i = 1; i <= h + w - 1; i++)
		cin >> p[i];
	dp[idx(h, w)] = max(p[h + w - 1] - a[idx(h, w)], 0ll);
	for (int i = h; i >= 1; i--) {
		for (int j = w; j >= 1; j--) {
			if (i == h && j == w) continue;
			int k = (i - 1) + (j - 1) + 1;
			if (i == h) dp[idx(i, j)] = max(dp[idx(i, j + 1)] + p[k] - a[idx(i, j)], 0ll);
			else if (j == w) dp[idx(i, j)] = max(dp[idx(i + 1, j)] + p[k] - a[idx(i, j)], 0ll);
			else dp[idx(i, j)] = min(max(dp[idx(i + 1, j)] + p[k] - a[idx(i, j)], 0ll), max(dp[idx(i, j + 1)] + p[k] - a[idx(i, j)], 0ll));
		}
	}
	cout << dp[idx(1, 1)] << endl;
	return 0;
}
