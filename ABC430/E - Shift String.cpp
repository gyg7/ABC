#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef unsigned long long ull;
const int N = 1e6 + 10;
char a[2 * N];
char b[N];
ull p[3][2 * N], P[3];
ull ap[3][2 * N], bp[3][N];
void pre() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	p[0][0] = 1, P[0] = 2;
	p[1][0] = 1, P[1] = 3;
	p[2][0] = 1, P[2] = 5;
	for (int i = 1; i < 2 * N; i++)
		for (int j = 0; j < 3; j++)
			p[j][i] = p[j][i - 1] * P[j];
}
void clear() {

}
void readmeta() {
	scanf("%s%s", a + 1, b + 1);
}
void solve() {
	int len = strlen(b + 1), len2 = 2 * len;
	for (int i = 1; i <= len; i++)
		a[i + len] = a[i];
	for (int j = 0; j < 3; j++) {
		for (int i = 1; i <= len; i++)
			bp[j][i] = bp[j][i - 1] * P[j] + b[i];
		for (int i = 1; i <= len2; i++)
			ap[j][i] = ap[j][i - 1] * P[j] + a[i];
	}
	ull hashb0 = bp[0][len], hashb1 = bp[1][len], hashb2 = bp[2][len];
	for (int i = 0; i < len; i++) {
		ull hasha0 = ap[0][i + len] - ap[0][i] * p[0][len];
		ull hasha1 = ap[1][i + len] - ap[1][i] * p[1][len];
		ull hasha2 = ap[2][i + len] - ap[2][i] * p[2][len];
		if (hasha0 == hashb0 && hasha1 == hashb1 && hasha2 == hashb2) {
			cout << i << endl;
			return;
		}
	}
	cout << -1 << endl;
}
signed main() {
	pre();
	int t = 1;
	scanf("%lld", &t);
	while (t--) {
		clear();
		readmeta();
		solve();
	}
	return 0;
}