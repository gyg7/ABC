#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, m, a, b, c, d;
char ch[1001][1001];
deque<pair<int, int>> q;
int dist[1001][1001];
bool vis[1001][1001];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> ch[i][j];
	cin >> a >> b >> c >> d;
	memset(dist, 0x3f, sizeof dist);
	q.push_back({a, b});
	dist[a][b] = 0;
	while (q.size()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			int w = 0;
			if (tx < 1 || tx > n) continue;
			if (ty < 1 || ty > m) continue;
			if (ch[tx][ty] == '#')
				w = 1;
			if (dist[tx][ty] > dist[x][y] + w) {
				dist[tx][ty] = dist[x][y] + w;
				if (w)
					q.push_back({tx, ty});
				else q.push_front({tx, ty});
			}
			int ttx = x + 2 * dx[i], tty = y + 2 * dy[i];
			if (ttx < 1 || ttx > n) continue;
			if (tty < 1 || tty > m) continue;
			if (ch[ttx][tty] == '#')
				w = 1;
			if (dist[ttx][tty] > dist[x][y] + w) {
				dist[ttx][tty] = dist[x][y] + w;
				if (w)
					q.push_back({ttx, tty});
				else q.push_front({ttx, tty});
			}
		}
	}
	cout << dist[c][d] << endl;
	return 0;
}