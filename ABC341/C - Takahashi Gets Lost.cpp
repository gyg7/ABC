#include <bits/stdc++.h>
using namespace std;
const int N = 511;
int n, h, w, ans;
char g[N][N], t[N];
bool jugde(int x, int y) {
	if (x < 1 || x > h) return 0;
	if (y < 1 || y > w) return 0;
	if (g[x][y] == '#') return 0;
	return 1;
}
bool check(int x, int y) {
	for (int i = 1; i <= n; i++) {
		if (t[i] == 'U') x--;
		if (t[i] == 'D') x++;
		if (t[i] == 'L') y--;
		if (t[i] == 'R') y++;
		if (jugde(x, y) == 0)
			return 0;
	}
	return 1;
}
int main() {
	cin >> h >> w >> n;
	scanf("%s", t + 1);
	for (int i = 1; i <= h; i++)
		scanf("%s", g[i] + 1);
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
			if (jugde(i, j) == 0) continue;
			if (check(i, j)) ans++;
		}
	printf("%d\n", ans);
	return 0;
}