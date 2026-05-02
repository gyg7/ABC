#include <bits/stdc++.h>
using namespace std;
int h, w;
char g[1001][1001];
int t, l, b, r;
int main() {
	cin >> h >> w;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> g[i][j];
	for (int i = 1; i <= h && t == 0; i++)
		for (int j = 1; j <= w && t == 0; j++)
			if (g[i][j] == '#') {
				t = i;
				break;
			}
	for (int i = h; i >= 1 && b == 0; i--)
		for (int j = 1; j <= w && b == 0; j++)
			if (g[i][j] == '#') {
				b = i;
				break;
			}
	for (int j = 1; j <= w && l == 0; j++)
		for (int i = 1; i <= h && l == 0; i++)
			if (g[i][j] == '#') {
				l = j;
				break;
			}
	for (int j = w; j >= 1 && r == 0; j--)
		for (int i = 1; i <= h && r == 0; i++)
			if (g[i][j] == '#') {
				r = j;
				break;
			}
	int cnt = 0;
	for (int i = t; i <= b; i++)
		for (int j = l; j <= r; j++)
			if (g[i][j] == '.') ++cnt;
	if (cnt) puts("No");
	else puts("Yes");
}