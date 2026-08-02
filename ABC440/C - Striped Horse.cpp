#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, w;
ll a[200001], sum[400001], sum2[800001];
int main() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> w;
		for (int j = 1; j <= n; j++)
			cin >> a[j];
		for (int j = 0; j < 2 * w; j++) sum[j] = 0;
		for (int j = 1; j <= n; j++) sum[j % (2 * w)] += a[j];
		for (int j = 0; j < 2 * w; j++) sum2[j] = (j ? sum2[j - 1] : 0) + sum[j];
		for (int j = 0; j < 2 * w; j++) sum2[j + 2 * w] = sum2[2 * w + j - 1] + sum[j];
		ll ans = 0x3f3f3f3f3f3f3f3f;
		for (int j = 0; j < 2 * w; j++) ans = min(ans, sum2[j + w] - sum2[j]);
		cout << ans << endl;
	}
}