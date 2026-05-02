#include <bits/stdc++.h>
using namespace std;
#define int long long
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int h, w;
char mp[300001];
bool vis[300001];
inline int idx(int x, int y) {
	return (x - 1) * w + y;
}
queue<pair<int, int>> que;
bool check(int x, int y) {
	if (x < 1 || x > h) return 0;
	if (y < 1 || y > w) return 0;
	if (vis[idx(x, y)]) return false;
	int cnt0 = 0;
	for (int k = 0; k < 4; k++) {
		int tx = x + dx[k], ty = y + dy[k];
		if (tx < 1 || tx > h || ty < 1 || ty > w) continue;
		if (mp[idx(tx, ty)] == '#')
			cnt0++;
	}
	return cnt0 == 1;
}
int ans;
void solve() {
	cin >> h >> w;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
			cin >> mp[idx(i, j)];
			if (mp[idx(i, j)] == '#') {
				que.push({i, j});
				vis[idx(i, j)] = 1;
				++ans;
			}
		}
	for (int i = 0; que.size(); i++) {
		queue<pair<int, int>> q2;
		for (int s = que.size(); s; s--) {
			auto [x, y] = que.front();

			que.pop();
			for (int k = 0; k < 4; k++) {
				int tx = x + dx[k], ty = y + dy[k];
				if (check(tx, ty)) {
					q2.push({tx, ty});
					vis[idx(tx, ty)] = 1;
					++ans;
				}
			}
		}
		for (int s = q2.size(); s; --s) {
			auto [x, y] = q2.front();
			q2.pop();
			mp[idx(x, y)] = '#';
			que.push({x, y});
		}
	}
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	int t = 1;
//	cin >> t;
	while (t--) solve();
}


