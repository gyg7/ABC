#include <bits/stdc++.h>
using namespace std;
int h, w, d, num;
char ch[1002][1002];
int vis[1002][1002];
queue<pair<int, int>> q;
int main() {
	cin >> h >> w >> d;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
			cin >> ch[i][j];
			if (ch[i][j] == 'H')
				q.push({i, j});
		}
	int cnt = 0;
	for (int i = 0; i <= d; i++) {
		for (int S = q.size(); S >= 1; --S) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (vis[x][y]) continue;
			vis[x][y] = 1;
			++cnt;
			if (ch[x - 1][y] == '.') q.push({x - 1, y});
			if (ch[x + 1][y] == '.') q.push({x + 1, y});
			if (ch[x][y - 1] == '.') q.push({x, y - 1});
			if (ch[x][y + 1] == '.') q.push({x, y + 1});

		}
	}
	cout<<cnt<<endl;
	return 0;
}