#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int mod = 998244353;
int n, p[N];
namespace BIT {
	int a[N];
	int lb(int x) {
		return x & -x;
	}
	void add(int x, int v) {
		while (x <= n) {
			a[x] += v;
			x += lb(x);
		}
	}
	int sum(int x) {
		int res = 0;
		while (x) {
			res += a[x];
			x -= lb(x);
		}
		return res;
	}
}
long long f[N], g[N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	long long ans = 0;
	for (int i = n; i >= 1; i--) {
		f[i] = BIT::sum(p[i]);
		g[i] = (g[i + 1] + g[i + 1] + f[i]) % mod;
		BIT::add(p[i], 1);
	}
	for (int i = 1; i <= n; i++) BIT::add(i, -1);
	for (int i = 1; i <= n; i++) {
		ans = (ans + 1ll * BIT::sum(p[i]) * (f[i] + g[i + 1])) % mod;
		BIT::add(p[i], 1);
	}
	cout << ans << endl;
}