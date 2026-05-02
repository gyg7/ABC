#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string s, t;
int nxt[N][26];
int main() {
	cin >> s >> t;
	int n = s.length(), m = t.length();
	for (int i = 0; i < 26; i++) nxt[n][i] = n;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i] - 'a'] = i;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int p = i;
		bool ok = true;
		for (int j = 0; j < m; j++) {
			p = nxt[p][t[j] - 'a'];
			if (p >= n) {
				ok = false;
				break;
			}
			p++;
		}
		if (ok) ans += (p - 1) - i;
		else ans += n - i;
	}
	cout << ans << endl;
}
