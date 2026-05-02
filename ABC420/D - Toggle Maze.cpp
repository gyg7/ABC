#include <bits/stdc++.h>
using namespace std;
#define int long long
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int t = 1;
int n, m, sx, sy, tx, ty;
char mp[501][501];
bool vis[501][501][2];
struct status {
	int x, y;
	bool flag;
};
queue<status> que;
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 'S') {
				sx = i, sy = j;
			}
			if (mp[i][j] == 'G') {
				tx = i, ty = j;
			}
		}
	que.push({sx, sy, false});
	for (int i = 0; que.size(); i++)
		for (int s = que.size(); s; s--) {
			status u = que.front();
			que.pop();
			int x = u.x, y = u.y;
			bool flag = u.flag;
			if (vis[x][y][flag]) continue;
			vis[x][y][flag] = true;
			if (x == tx && y == ty) {
				cout << i << endl;
				return;
			}
			for (int k = 0; k < 4; k++) {
				int tx = x + dx[k], ty = y + dy[k];
				bool tf = flag;
				if (tx < 1 || tx > n) continue;
				if (ty < 1 || ty > m) continue;
				if (mp[tx][ty] == '#') continue;
				if (mp[tx][ty] == 'o' && flag) continue;
				if (mp[tx][ty] == 'x' && !flag) continue;
				if (mp[tx][ty] == '?') tf ^= 1;
				que.push({tx, ty, tf});
			}
		}
	puts("-1");
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	//cin>>t;
	while (t--) solve();
	return 0;
}


