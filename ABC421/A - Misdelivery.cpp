#include <bits/stdc++.h>
using namespace std;
#define int long long
int T = 1;
int n, x;
string s, y;
unordered_map<string, unordered_set<int>> mp;
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		mp[s].insert(i);
	}
	cin >> x >> y;
	if (mp[y].count(x)) puts("Yes");
	else puts("No");
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	//cin >> T;
	while (T--) solve();
	return 0;
}


