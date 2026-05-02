#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a;i<=b;++i)
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long f[510][510], n, m, a, b, c, k, t, d, opt, q;
void solve(int k) {
	rep(i, 1, n + 1) rep(j, 1, n + 1) if (f[i][j] > f[i][k] + f[k][j]) f[i][j] = f[i][k] + f[k][j];
}
int main() {
	cin >> n >> m;
	memset(f, inf, sizeof f);
	rep(i, 1, n + 1) f[i][i] = 0;
	rep(i, 1, m) {
		cin >> a >> b >> c;
if(f[a][b]>c){
		f[a][b] = f[b][a] = c;}
	}
	cin >> k >> t;
	rep(i, 1, k) {
		cin >> d;
		f[d][n + 1] = t;
		f[n + 1][d] = 0;
	}
	rep(k, 1, n + 1) solve(k);
	cin >> q;
	rep(i, 1, q) {
		cin >> opt;
		if (opt == 3) {
			long long ans = 0;
			rep(i, 1, n) rep(j, 1, n) if (f[i][j] != inf) ans += f[i][j];
			cout << ans << endl;
		} else if (opt == 1) {
			cin >> a >> b >> c;
			if (f[a][b] > c) {
				f[a][b] = f[b][a] = c;
				solve(a), solve(b);
			}
		} else {
			cin >> d;
			if (f[d][n + 1] > t) {
				f[d][n + 1] = t;
				f[n + 1][d] = 0;
				solve(d), solve(n + 1);
			}
		}
	}
	return 0;
}
