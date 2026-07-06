#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;
void solve() {
	string s;
	cin >> s;
	int n = s.size();
	mint dp[3][2] = {{0}};
	for (int i = 1; i <= n; i++) {
		int c = s[i-1] - 'a';
		mint prev[3][2];
		memcpy(prev, dp, sizeof(prev));
		mint total_prev = 1;
		for (int x = 0; x < 3; x++) {
			total_prev = total_prev + prev[x][0] + prev[x][1];
		}
		mint endC_prev = prev[c][0] + prev[c][1];
		dp[c][1] = total_prev - endC_prev;
		dp[c][0] = endC_prev;
		for (int ch = 0; ch < 3; ch++) {
			if (ch == c) continue;
			dp[ch][1] = 0;
			dp[ch][0] = prev[ch][0] + prev[ch][1];
		}
	}
	mint ans = 0;
	for (int ch = 0; ch < 3; ch++) 
		ans = ans + dp[ch][0] + dp[ch][1];
	cout << ans.val() << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
