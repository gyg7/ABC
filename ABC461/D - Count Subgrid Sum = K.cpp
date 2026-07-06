#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char s[501][501];
int a[501][501];
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> s[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == '1') a[i][j]++;
			a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];

		}
	}
	int ans = 0;
	for (int x1 = 1; x1 <= n; x1++) {
		for (int x2 = x1; x2 <= n; x2++) {
			for (int y1 = 1; y1 <= m; y1++) {
				for (int y2 = y1; y2 <= m; y2++) {
					int sm = a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
					if (sm == k) {
						++ans;
					}
				}
			}
		}
	}
	cout << ans << endl;
}
