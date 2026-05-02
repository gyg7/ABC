#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

const int N = 2e5 + 10;
const int P = 1e7 + 10;
int vis[P], tot, prime[P];
int n, a[N];
ll ksm(ll x, ll y) {
	ll res = 1;
	x %= mod;
	while (y) {
		if (y & 1) res = (res * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return res;
}
void solve() {
	cin >> n;
	unordered_map<int, int> e1, e2;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int x = a[i];
		while (vis[x]) {
			int p = vis[x], cnt = 0;
			while (x % p == 0) {
				x /= p;
				++cnt;
			}
			if (cnt > e1[p]) {
				e2[p] = e1[p];
				e1[p] = cnt;
			} else if (cnt > e2[p])
				e2[p] = cnt;
		}
	}
	ll ans = 1;
	for (auto [p, e] : e1) {
		ans = (ans * ksm(p, e)) % mod;
		ans = (ans % mod + mod) % mod;
	}
	for (int i = 1; i <= n; i++) {
		ll res = ans;
		int x = a[i];
		while (vis[x]) {
			int p = vis[x], cnt = 0;
			while (x % p == 0) {
				cnt++;
				x /= p;
			}
			if (cnt == e1[p]) {
				ll v = ksm(ksm(p, e1[p]), mod - 2);
				res = (res * v % mod * ksm(p, e2[p])) % mod;
			}
		}
		cout << (res % mod + mod) % mod << " \n"[i == n];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	for (int i = 2; i < P; i++) {
		if (vis[i] == 0) {
			prime[++tot] = i;
			vis[i] = i;
		}
		for (int j = 1; j <= tot && i * prime[j] < P; j++) {
			vis[i * prime[j]] = prime[j];
			if (i % prime[j] == 0) break;
		}
	}
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}