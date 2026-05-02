#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
bool vis[1 << 18];
bool dfs(int status) {
	if (vis[status]) return false;
	vis[status] = true;
	if (status == (1 << n) - 1) return true;
	for (int i = 1; i <= n; i++) {
		if ((status >> (i - 1)) & 1) continue;
		int now = status | (1 << (i - 1));
		if (s[now - 1] == '0' && dfs(now)) return true;
	}
	return false;
}
int main() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> s;
		memset(vis, 0, sizeof vis);
		if (dfs(0)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
