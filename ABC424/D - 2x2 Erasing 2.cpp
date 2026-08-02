#include <bits/stdc++.h>
using namespace std;
#define int long long
int T = 1;
int h, w;
char ch;
int dp[8][1 << 8], a[8], u;
bool isbit(int s, int x) {
	return (s >> (x - 1)) & 1;
}
int ans = 0;
bool check(int s, int p) {
	for (int i = 1; i < w; i++) {
		if (isbit(s, i) && isbit(s, i + 1) && isbit(p, i)
		        && isbit(p, i + 1))
			return false;
	}
	return true;
}
int cast(int i, int s) {
	int cnt = 0;
	for (int j = 1; j <= w; j++)
		if (isbit(a[i], j) && isbit(s, j) == 0)
			++cnt;
	return cnt;
}
void solve() {
	cin >> h >> w;
	u = 1 << w;
	memset(a, 0, sizeof a);
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
			cin >> ch;
			if (ch == '#')
				a[i] |= (1 << (j - 1));
		}
	memset(dp, 0x3f, sizeof dp);
	for (int s = 0; s < u; s++)
		dp[1][s] = cast(1, s);
	cout << endl;
	for (int i = 2; i <= h; i++)
		for (int s = 0; s < u; s++)
			for (int p = 0; p < u; p++)
				if (check(s, p))
					dp[i][s] = min(dp[i][s], dp[i - 1][p] + cast(i, s));
	ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = 0; i < u; i++)
		if (dp[h][i] < ans) ans = dp[h][i];
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	cin >> T;
	while (T--) solve();
	return 0;
}