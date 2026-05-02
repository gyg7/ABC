#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, f[1 << 22];
string T;
void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}
/*»ù´¡¹Ç¼Ü*/
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
	cin >> n >> T;

}
void solve() {
	f[(1 << n ) - 1] = 1;
	for (int i = (1 << n) - 1; i; --i) {
		if (f[i] == 0) continue;
		char lst = '?';
		for (int k = 0; k < n; k++) {
			if (!(i & (1 << k))) continue;
			if (lst != T[k]) add(f[i ^ (1 << k)], f[i]);
			lst = T[k];
		}
	}
	cout << f[0] << endl;
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
}
