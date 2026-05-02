#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;
typedef long long ll;
int n, q, a[N][64], b;
ll sum[N][64];
ll t;
int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0];
		sum[i][0] = i;
	}
	for (int j = 1; j <= 63; j++) {
		for (int i = 1; i <= n; i++) {
			a[i][j] = a[a[i][j - 1]][j - 1];
			sum[i][j] = sum[i][j - 1] + sum[a[i][j - 1]][j - 1];
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> t >> b;
		ll ans = 0;
		for (int j = 63; j >= 0; j--) {
			if ((t >> j) & 1) {
				ans = ans + sum[b][j];
				b = a[b][j];
			}
		}
		cout << ans << endl;
	}
}