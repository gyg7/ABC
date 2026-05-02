#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, p[1001], v[1001];
int dp[1011][50001], dp2[1010][50001], f[50001];
char cnt[1001];
signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> v[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 0; --j){
            if(j>=p[i])
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p[i]] + v[i]);
            else dp[i][j]=dp[i-1][j];
            }
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 0; --j){
            if(j>=p[i]) dp2[i][j] = max(dp2[i + 1][j], dp2[i + 1][j - p[i]] + v[i]);
            else dp2[i][j]=dp2[i+1][j];
            }
	int V = dp[n][m];
	for (int i = 1; i <= n; i++) {
		int ans = 0, ans2 = 0;
		for (int k = m; k >= 0; --k)
			ans = max(ans, dp[i - 1][k] + dp2[i + 1][m - k]);
		for (int k = m - p[i]; k >= 0; --k) ans2 = max(ans2, dp[i - 1][k] + dp2[i + 1][(m - p[i]) - k]);
		if (ans < V) cnt[i] = 'A';
		else if (ans2 + v[i] == V) cnt[i] = 'B';
		else cnt[i] = 'C';
		cout << cnt[i];
	}

}