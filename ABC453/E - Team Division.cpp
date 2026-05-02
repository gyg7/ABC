#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 998244353;
typedef long long ll;
int n, l, r, a[N], b[N], both[N];
int diffa[N], diffb[N], diffboth[N];
ll ksm(ll x, int y) {
	ll res = 1;
	while (y) {
		if (y & 1) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
ll fac[N], inv[N];
#define C(n,k) (fac[n]*inv[k]%mod*inv[n-k]%mod)
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> l >> r;
		diffa[l]++;
		diffa[r + 1]--;
		int lb = n - r, rb = n - l;
		if (lb <= rb) {
			diffb[lb]++;
			diffb[rb + 1]--;
		}
		int lb2 = max(l, lb), rb2 = min(r, rb);
		if (lb2 <= rb2) {
			diffboth[lb2]++;
			diffboth[rb2 + 1]--;
		}
	}
	for (int i = 1; i <= n; i++) {
		a[i] = diffa[i] + a[i - 1];
		b[i] = b[i - 1] + diffb[i];
		both[i] = both[i - 1] + diffboth[i];;
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	inv[n] = ksm(fac[n], mod - 2);
	for (int i = n - 1; i >= 0; i--)
		inv[i] = (inv[i + 1] * (i + 1)) % mod;
	ll ans = 0;
	for (int k = 1; k < n; k++) {
		int onlyA = a[k] - both[k], onlyb = b[k] - both[k], bo = both[k];
		int none = n - a[k] - b[k] + both[k];
		if (none) continue;
		int need = k - onlyA;
		if (need < 0 || need > bo) continue;
		ans = (ans + C(bo, need)) % mod;
	}
	cout << ans << endl;
}