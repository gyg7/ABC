#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int dd[] = {2, 3, 0, 1};
int n, w, k;
int ans, g[12][12], vis[12][12];
char ch[11][11];
int dfs(int x, int y, int k) {
	int ans = 0;
	if (k == 0) return 1;
	vis[x][y] = 1;
	for (int fd = 0; fd <= 3; fd++) {
		int tx = x + dx[fd], ty = y + dy[fd];
		if (g[tx][ty] && vis[tx][ty] == 0)
			ans += dfs(tx, ty, k - 1);
	}
	vis[x][y] = 0;
	return ans;
}
int main() {
	cin >> n >> w >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= w; j++) {
			cin >> ch[i][j];
			g[i][j] = (ch[i][j] == '.');
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= w; j++)
				if (ch[i][j] == '.')
					ans += dfs(i, j, k);
	cout << ans << endl;
	return 0;
}