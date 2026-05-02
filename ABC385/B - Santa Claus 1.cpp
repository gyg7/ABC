#include <bits/stdc++.h>
using namespace std;
int h, w, x, y, cnt;
char s[111][111];
bool vis[111][111];
string str;

int main() {
	cin >> h >> w >> x >> y;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> s[i][j];
	if (vis[x][y] == 0 && s[x][y] == '@') ++cnt;
	vis[x][y] = 1;
	for (int i = 0; i <= h + 1; i++)
		s[i][0] = '#';
	for (int i = 0; i <= w + 1; i++)
		s[0][i] = '#';
	cin >> str;
	for (char ch : str) {
		if (ch == 'U') {
			if (s[x - 1][y] == '#') continue;
			x--;
			if (vis[x][y] == 0 && s[x][y] == '@') ++cnt;
			vis[x][y] = 1;
		}
		if (ch == 'D') {
			if (s[x + 1][y] == '#') continue;
			x++;
			if (vis[x][y] == 0 && s[x][y] == '@') ++cnt;
			vis[x][y] = 1;
		}
		if (ch == 'L') {
			if (s[x][y - 1] == '#') continue;
			y--;
			if (vis[x][y] == 0 && s[x][y] == '@') ++cnt;
			vis[x][y] = 1;
		}
		if (ch == 'R') {
			if (s[x][y + 1] == '#') continue;
			y++;
			if (vis[x][y] == 0 && s[x][y] == '@') ++cnt;
			vis[x][y] = 1;
		}
	}
	cout << x << " " << y << " " << cnt;
}