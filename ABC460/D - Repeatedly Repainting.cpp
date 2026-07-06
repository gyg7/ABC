#include <bits/stdc++.h>
using namespace std;
#define N 1000010
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int h, w;
char ch[N], ch2[N];
int pos(int i, int j) {
	return (i - 1) * w + j;
}
int dist[N];
bool vis[N];
void trans() {
	swap(ch, ch2);
	for (int i = 1; i <= h * w; i++) {
		if (ch2[i] == '#') ch[i] = '.';
		else {
			ch[i] = '.';
			int x = (i - 1) / w + 1, y = (i - 1) % w + 1;
			for (int d = 0; d < 8; d++) {
				int xx = x + dx[d], yy = y + dy[d];
				if (xx <= 0 || xx > h || yy <= 0 || yy > w) continue;
				if (ch2[pos(xx, yy)] == '#') {
					ch[i] = '#';
					break;
				}
			}
		}
	}
}
int main() {
	cin >> h >> w;
	queue<int> que;
	for (int i = 1; i <= h * w; i++) {
		cin >> ch[i];
		if (ch[i] == '#') {
			vis[i] = 1;
			que.push(i);
		}
	}
	while (que.size()) {
		int u = que.front();
		int x = (u - 1) / w + 1, y = (u - 1) % w + 1;
		que.pop();
		for (int i = 0; i < 8; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (tx <= 0 || tx > h || ty <= 0 || ty > w) continue;
			if (vis[pos(tx, ty)] == 0) {
				vis[pos(tx, ty)] = 1;
				dist[pos(tx, ty)] = dist[u] ^ 1;
				que.push(pos(tx, ty));
			}
		}
	}
	for (int i = 1; i <= h * w; i++) {
		printf("%c", "#."[dist[i]]);
		if ((i - 1) % w + 1 == w) puts("");
	}
}
