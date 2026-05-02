#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 101;
int n, m, a[N];
struct node {
	int b, c;
} p[N];
bool cmp(node a, node b) {
	return a.b > b.b;
}
int Left[N], dp[N][N][N * N];
void ckmax(int &x, int y) {
	if (x < y) x = y;
}
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> p[i].b >> p[i].c;
	sort(p + 1, p + 1 + m, cmp);
	for (int k = 0; k <= m; k++)
		for (int i = 1; i <= n; i++)
			Left[k] += min(a[i], k);
	memset(dp, -0x3f, sizeof dp);
    dp[0][0][0]=0;
	for (int i = 1; i <= m; i++)
		for (int j = 0; j <= m; j++)
			for (int s = 0; s <= n * m; s++) {
				dp[i][j][s] = dp[i - 1][j][s];
				if (j && s - p[i].b >= 0 && Left[j] >= s)
					ckmax(dp[i][j][s], dp[i - 1][j - 1][s - p[i].b] + p[i].c);
			}
	int ans = -0x3f3f3f3f3f3f;
	for (int i = 0; i <= m; i++)
		for (int s = 0; s <= n * m; s++)
			ckmax(ans, dp[m][i][s]);
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	int T = 1;
	//cin >> T;
	while (T--) solve();
	return 0;
}