#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
int n, m;
char ch[1010][1010];
bool vis[1010][1010];
void dfs(int x, int y) {
	if (x < 1 || x > n || y < 1 || y > m) return;
	if (ch[x][y] == '#' || vis[x][y]) return;
	vis[x][y] = true;
	for (int i = 0; i < 4; i++)
		dfs(x + dx[i], y + dy[i]);
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> ch[i][j];
	for (int i = 1; i <= n; i++) {
		if (vis[i][1] == 0 && ch[i][1] == '.') dfs(i, 1);
		if (vis[i][m] == 0 && ch[i][m] == '.') dfs(i, m);
	}
	for (int i = 1; i <= m; i++) {
		if (vis[1][i] == 0 && ch[1][i] == '.') dfs(1, i);
		if (vis[n][i] == 0 && ch[n][i] == '.') dfs(n, i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (ch[i][j] == '.' && vis[i][j] == 0) {
				++ans;
				dfs(i, j);
			}
	}
    cout<<ans<<endl;
}