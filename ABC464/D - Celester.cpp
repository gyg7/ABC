#include <bits/stdc++.h>
using namespace std;
int x[200010], y[200001];
long long dp[200010][2];

void solve() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> y[i];
    }
    dp[1][0] = s[0] != 'S' ? -x[1] : 0;
    dp[1][1] = s[0] != 'R' ? -x[1] : 0;
    for (int i = 2; i <= n; i++) {
        bool n2 = s[i - 1] == 'S';
        long long cost0 = n2 ? 0 : -x[i];
        long long cost1 = n2 ? -x[i] : 0;
        
        dp[i][0] = max(dp[i - 1][0] + cost0,
                       dp[i - 1][1] + y[i - 1] + cost0);
        dp[i][1] = max(dp[i - 1][0] + cost1,
                       dp[i - 1][1] + cost1);
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
}
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
	return 0;
}