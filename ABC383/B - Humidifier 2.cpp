#include <bits/stdc++.h>
using namespace std;
int h, w, d, num;
char ch[11][11];
int vis[11][11];
pair<int, int>ve[101];
int dist(int i, int j) {
	return abs(ve[i].first - ve[j].first) + abs(ve[i].second - ve[j].second);
}
int main() {
	cin >> h >> w >> d;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> ch[i][j];
			if (ch[i][j] == '.')
				ve[++num] = {i, j};
		}
	}
	int mx = 0;
	for (int i = 1; i <= num; i++) {
		for (int j = i + 1; j <= num; j++) {
			int cnt = 0;
			for (int x = 1; x <= num; x++)
				if (i == x || j == x | dist(i, x) <= d || dist(x, j) <= d)
					++cnt;
			mx = max(mx, cnt);
		}
	}
	cout << mx << endl;
	return 0;
}