#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
ll n, m,sum;
int main() {
	cin >> n >> m;
	for (int i = 0; i <= 60; i++) {
		if (m & (1ll << i)) {
			ll p = (1ll << i);
			sum += (n / (2 * p)) *  p;
			ll l = n % (2 * p);
			if (l >= p) sum += l - p + 1;
			sum %= mod;
		}
	}
	printf("%lld", sum);
	return 0;
}