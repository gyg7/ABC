#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 __;
const int mod = 998244353;
ll n, m;

__ gcdm(__ n, __ m) {
	return m ? gcdm(m, n % m) : n;
}
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> m;
		int ans = 0;
		__ pw = 1;
		for (; pw <= n; pw *= 10) {
			__ d = gcdm(m, pw * 10 - 1);
			__ v0 = (n / (m / d)) % mod;
			__ v1 = (min((__)n, pw * 10 - 1) - pw + 1) % mod;
			(ans += 1ll * v0 * v1 % mod) %= mod;
		}
		cout << ans << endl;
	}
}
