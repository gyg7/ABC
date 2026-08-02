#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+100;
int p[N], tot;
bitset<N> vis, vis2;
typedef long long ll;
int main() {
	for (int i = 2; i < N; i++) {
		if (vis[i] == 0)
			p[++tot] = i;
		for (int j = 1; j <= tot && i * p[j] < N; j++) {
			vis[i * p[j]] = 1;
			if (i % p[j] == 0)
				break;

		}
	}
	ll l, r, ans;
	cin >> l >> r;
	for (int i = 1; i <= tot; i++) {
		for (ll j = (l / p[i] + 1) * p[i]; j <= r; j += p[i]) {
			if (vis2[j - (l + 1)]) continue;
			vis2[j - (l + 1)] = true;
			ll y = j;
			while (y % p[i] == 0) {
				y /= p[i];
			}
			if (y == 1) ans++;
		}
	}
	for (int i = 0; i <r - l + 1; i++) {
		if(!vis2[i])ans++;
	}
	cout << ans << endl;
	return 0;
}