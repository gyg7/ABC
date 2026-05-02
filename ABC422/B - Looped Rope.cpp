#include <bits/stdc++.h>
using namespace std;
#define int long long
int T = 1;
int h, w;
char ch[22][22];
void solve() {
	cin >> h >> w;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> ch[i][j];
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
			if (ch[i][j] == '.') continue;
			int cnt = 0;
			if (ch[i - 1][j] == '#') ++cnt;
			if (ch[i + 1][j] == '#') ++cnt;
			if (ch[i][j - 1] == '#') ++cnt;
			if (ch[i][j + 1] == '#') ++cnt;
			if (cnt != 2 && cnt != 4) {
				puts("No");
				return;
			}
		}
	puts("Yes");
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


