#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long n, m, a[300010], b[300010], pre[300010], suf[300010];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	for (int i = 1; i <= m; i++)
		pre[i] = (pre[i - 1] + b[i]) % mod;
	for (int i = m; i >= 1; i--)
		suf[i] = (suf[i + 1] + b[i]) % mod;

	int j = 1;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		while (j <= m && a[i] > b[j]) j++;
		long long var = ((j - 1) * a[i] - pre[j - 1] + suf[j] - (m - j + 1) * a[i]) % mod;
		ans = (ans + var) % mod;
		ans = (ans + mod) % mod;
	}
	cout << ans << endl;
}
