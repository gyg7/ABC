#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 5e5 + 10;
int n, m;
ll a[N], b[N];
ll sm[N], sma2;
void add(ll &x, ll y) {
	x += y;
	if (x >= mod) x -= mod;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sma2 = (sma2 + a[i] * i % mod) % mod;
		sm[i] = (sm[i - 1] + a[i]) % mod;
	}
	ll smb = 0;
	for (int j = 1; j <= m; j++) {
		cin >> b[j];
		add(smb, b[j]);
	}
	ll sum =  (smb * sma2) % mod;
	for (int j = 1; j <= m; j++) {
		ll res = 0;
		for (int k = 1; j * k <= n; k++) {
			int l = j * k;
			int r = min(n, j * (k + 1) - 1);
			add(res, k * (sm[r] - sm[l - 1] + mod) % mod);
		}
		add(sum, mod - (b[j]*j % mod * res % mod));
	}
	cout << sum << endl;
}