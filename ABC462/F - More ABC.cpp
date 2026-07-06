#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+5, K = 12, INF = 1e9;
char s[N];
int z[N], dp[N][K];
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int k;
		scanf("%s%d", s + 1, &k);
		int n = strlen(s + 1);
		for (int i = 0; i <= n; i++)
			z[i] = 0;
		for (int i = 3; i <= n; i++)
			if (s[i - 2] == 'A' && s[i - 1] == 'B' && s[i] == 'C')
				z[i] = 1;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= k; j++) {
				dp[i][j] = INF;
			}
		}
		for (int i = 0; i <= n; i++) dp[i][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				if (j + z[i] <= k) {
					dp[i][j] = min(dp[i][j], dp[i - 1][j + z[i]]);
				}
				if (i >= 3) {
					int x = z[i - 2] + z[i - 1] + z[i];
					int y = (s[i - 2] != 'A') + (s[i - 1] != 'B') + (s[i] != 'C');
					int need = j - 1 + x;
					if (need <= k) {
						dp[i][j] = min(dp[i][j], dp[i - 3][need] + y);
					}
				}
			}
		}
		int ans = dp[n][k];
		if (ans == INF) ans = -1;
		cout << ans << endl;
	}
	return 0;
}