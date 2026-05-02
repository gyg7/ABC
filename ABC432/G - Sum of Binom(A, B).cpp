#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/convolution>
using namespace std;
using namespace atcoder;
typedef modint998244353 mint;
const int maxn = 5e5 + 10;
mint fac[maxn], inv[maxn];
int n, m, a[maxn], b[maxn];
vector<mint> x,y;
void pre() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
}
void clear() {

}
void readmeta() {
	fac[0] = 1;
	for (int i = 1; i < maxn; i++)
		fac[i] = fac[i - 1] * i;
	inv[maxn - 1] = 1 / fac[maxn - 1];
	for (int i = maxn - 2; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
    for(int i = 1;i<=m;i++) cin>>b[i];

}
void solve() {
x.resize(maxn);
y.resize(maxn);
	for (int i = 1; i <= m; i++) x[b[i]] += inv[b[i]];
	for (int i = 0; i < maxn; i++)
		y[i] = inv[i];
	auto z = convolution(x, y);
	mint ans = 0;
	for (int i = 1; i <= n; i++) 
		ans+=fac[a[i]]*z[a[i]];
	cout<<ans.val()<<endl;
}
signed main() {
	pre();
	int t = 1;
//	cin >> t;
	while (t--) {
		clear();
		readmeta();
		solve();
	}
	return 0;
}
