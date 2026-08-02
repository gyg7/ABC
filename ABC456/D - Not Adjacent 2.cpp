#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	
	int dp[3][2] = {{0}};  // [ch][0/1]
	
	for (int i = 1; i <= n; i++) {
		int c = s[i-1] - 'a';
		
		// 保存上一轮
		int prev[3][2];
		memcpy(prev, dp, sizeof(prev));
		
		// 计算 total_prev（含空序列）
		long long total_prev = 1;  // 空序列
		for (int x = 0; x < 3; x++) {
			total_prev = (total_prev + prev[x][0] + prev[x][1]) % MOD;
		}
		
		// 计算 endC_prev
		long long endC_prev = (prev[c][0] + prev[c][1]) % MOD;
		
		// 更新 dp
		dp[c][1] = (total_prev - endC_prev + MOD) % MOD;  // 关键：不需要 +1
		dp[c][0] = endC_prev;
		
		for (int ch = 0; ch < 3; ch++) {
			if (ch == c) continue;
			dp[ch][1] = 0;
			dp[ch][0] = (prev[ch][0] + prev[ch][1]) % MOD;
		}
	}
	
	long long ans = 0;
	for (int ch = 0; ch < 3; ch++) {
		ans = (ans + dp[ch][0] + dp[ch][1]) % MOD;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}