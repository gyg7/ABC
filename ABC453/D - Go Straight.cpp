#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
const char chs[] = "LURD";
char ch[1050][1050];
bool vis[1050][1050][5];
int h, w;
char pre[1050][1050][5];
struct node {
	int x, y, dir;
};
queue<node> que;
int sx, sy, tx, ty;
void dfs(int x, int y, int k) {
	for (int i = 0; i < 4; i++)
		if (pre[x][y][k] == chs[i]) dfs(x - dx[k], y - dy[k], i);
	putchar(chs[k]);
}
int main() {
	cin >> h >> w;

	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
			cin >> ch[i][j];
			if (ch[i][j] == 'S') sx = i, sy = j;
			if (ch[i][j] == 'G') tx = i, ty = j;
		}
	for (int i = 0; i < 4; i++) {
		int tx = sx + dx[i], ty = sy + dy[i];
		if (tx < 1 || tx > h || ty < 1 || ty > w) continue;
		if (ch[tx][ty] == '#') continue;
		vis[tx][ty][i] = 1;
		que.push({tx, ty, i});
	}
	for (; que.size();) {
		for (int s = que.size(); s; --s) {
			auto [x, y, dir] = que.front();
			que.pop();
			for (int i = 0; i < 4; i++) {
				int tx = x + dx[i], ty = y + dy[i];
				if (tx < 1 || tx > h || ty < 1 || ty > w) continue;
				if (ch[tx][ty] == '#' || vis[tx][ty][i]) continue;
				if (ch[x][y] == 'o') {
					if (dir == i) {
						vis[tx][ty][i] = 1;
						pre[tx][ty][i] = chs[dir];
						que.push({tx, ty, i});
					}
				} else if (ch[x][y] == 'x') {
					if (dir != i) {
						vis[tx][ty][i] = 1;
						pre[tx][ty][i] = chs[dir];
						que.push({tx, ty, i});
					}
				} else {
					vis[tx][ty][i] = 1;
					pre[tx][ty][i] = chs[dir];
					que.push({tx, ty, i});
				}
			}
		}
	}
	for (int i = 0; i <= 4; i++) {
		if (i == 4) puts("No");
		else if (vis[tx][ty][i]) {
			puts("Yes");
			dfs(tx, ty, i);
			break;
		}
	}
}