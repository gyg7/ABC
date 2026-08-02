#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
const int mod = 998244353; 
typedef modint998244353 mint;
typedef long long ll;
int main() {
	ll l = 2, r, n;
	mint ans = 0;
	cin >> n;
    const ll inv2 = (mod+1)/2;
	while (l <= n - 1) {
		r = min(n - 1, n / (n / l));
		mint val = n / l,len = r-l+1;
		mint sm1 = (mint)len * (r-1 + l - 1) *inv2 * (val - 1);
		mint sm2 = (mint)len * n - (r + l) * len * inv2 * val;
		ans += sm1 + sm2;
l = r +1;
	}
	cout << ans.val() << endl;
	return 0;
}