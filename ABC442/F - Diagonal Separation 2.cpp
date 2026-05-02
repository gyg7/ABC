
#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int n;
char s[N][N];
int f[N][N], suf[N][N], pre[N][N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> s[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			pre[i][j] = pre[i][j - 1] + (s[i][j] == '#');
		for (int j = n; j >= 1; j--)
			suf[i][j] = suf[i][j + 1] + (s[i][j] == '.');
		int mn = 1e9;
		for (int j = n; j >= 0; --j) {
			mn = min(mn, f[i - 1][j]);
			f[i][j] = mn + pre[i][j] + suf[i][j + 1];
		}
	}
	int ans = 1e9;
	for (int i = 0; i <= n; i++)
		ans = min(ans, f[n][i]);
	cout << ans << endl;
}