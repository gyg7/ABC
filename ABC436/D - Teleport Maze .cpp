#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int h, w;
char s[1010][1010];
vector<pair<int, int>> ve[27];
int dist[1010][1010];
int main() {
	cin >> h >> w;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
			cin >> s[i][j];
			if ('a' <= s[i][j] && s[i][j] <= 'z')
				ve[s[i][j] - 'a'].push_back({i, j});
		}
	memset(dist, 0x3f, sizeof dist);
	queue<pair<int, int>> que;
	que.push({1, 1});
	dist[1][1] = 0;
	while (que.size()) {
		auto [x, y] = que.front();	que.pop();
		if (x < 1 || x > h || y < 1 || y > w) continue;
		if (s[x][y] == '#') continue;
	
		if ('a' <= s[x][y] && s[x][y] <= 'z'){
			for (auto [tx, ty] : ve[s[x][y] - 'a'])
				if (dist[tx][ty] > dist[x][y] + 1) {
					dist[tx][ty] = dist[x][y] + 1;
					que.push({tx, ty});
				}
            ve[s[x][y]-'a'].clear();
        }
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (dist[tx][ty] > dist[x][y] + 1) {
				dist[tx][ty] = dist[x][y] + 1;
				que.push({tx, ty});
			}
		}
	}
	if (dist[h][w] == 0x3f3f3f3f) dist[h][w] = -1;
	cout << dist[h][w] << endl;
}