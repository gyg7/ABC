#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int mod = 998244353;
const int N = 2e5 + 10;
int n;
ll a[N];
ll inv[N], f[N];
signed main() {
	cin >> n;
	inv[1] = 1;
	for (int i = 2; i < N; i++) inv[i] = (mod - 1ll * (mod / i) * inv[mod % i]) % mod;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n == 1) {
		printf("%lld\n", 1ll * a[1]*a[1] % mod);
		return 0;
	}

	f[2] = 0;
	for (int i = 3; i <= n; i++) {
		ll tmp = (1ll * (i - 2) * (i - 3) % mod * f[i - 1] % mod + 2ll * (i - 2) % mod) % mod;
		tmp = (1ll * tmp * inv[i] % mod * inv[i - 1]) % mod;
		f[i] = tmp;
	}

	ll E = (2ll * f[n] % mod - 1 + mod) % mod;
	ll sm1 = 0, sm2 = 0;
	for (int i = 1; i <= n; i++) {
		(sm1 += a[i]) %= mod;
		(sm2 += 1ll * a[i] * a[i] % mod) %= mod;
	}
	ll cross = (1ll * sm1 * sm1 % mod - sm2 + mod) % mod;
	ll ans = (sm2 + 1ll * cross * E % mod) % mod;
	cout << ans << endl;
}