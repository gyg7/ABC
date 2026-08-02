#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef modint998244353 mint;
const int N = 3e5+10;
int n;
ll c, a[N];
mint pre[N], f[N];
mint s;
int main() {
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];

	}
	a[c]++;
	int tmp = a[c];
	sort(a + 1, a + 1 + n);
	c = lower_bound(a + 1, a + 1 + n, tmp) - a;
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i]/s;
	}
	mint sum = 1;
	for (int i = n; i >= c; i--) {
		f[i] = sum / (1 - pre[i - 1]);
		sum = sum + f[i] * a[i] / s;
	}
	cout << f[c].val() << endl;
	return 0;
}