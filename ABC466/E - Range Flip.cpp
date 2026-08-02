#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int n, k, a[N], b[N];
long long dp[20][2], newdp[20][2];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	memset(dp, -0x3f, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		memset(newdp, -0x3f, sizeof newdp);
		for (int j = k; j >= 0; --j) {
			if (dp[j][0] > -inf) {
				newdp[j][0] = max(newdp[j][0], dp[j][0]);
				if (j < k)
					newdp[j][1] = max(newdp[j][1], dp[j][0] + b[i] - a[i]);
			}
			if (dp[j][1] > -inf) {
				newdp[j][1] = max(newdp[j][1], dp[j][1] + b[i] - a[i]);
				if (j < k) {
					newdp[j + 1][0] = max(newdp[j + 1][0], dp[j][1]);
				}
			}
		}
		swap(dp, newdp);
	}
	long long sum = 0, ext = 0;
	for (int i = 1; i <= n; i++) sum += a[i];
	for (int i = 0; i <= k; i++) {
		ext = max({ext, dp[i][0], dp[i][1]});
	}
	cout << sum + ext << endl;
	return 0;
}