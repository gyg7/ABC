#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
string s[10];
void pre() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
}
void clear() {

}
void readmeta() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
}
void solve() {
	string str;
	unordered_set<string> unset;
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			str = "";
			for (int k = 0; k < m; k++) str += s[i + k].substr(j, m);
			unset.insert(str);
		}
	}
	cout << unset.size() << endl;
}
signed main() {
	pre();
	int t = 1;
//	cin >> t;
	while (t--) {
		clear();
		readmeta();
		solve();
	}
	return 0;
}
