#include <bits/stdc++.h>
using namespace std;
const int B = 300000;
void slove() {
	int n, m;
	vector<vector<char>> g, tp;
	cin >> n >> m;
	g.assign(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
		}
	}
	if (n > m) {
		tp.assign(m, vector<char>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tp[j][i] = g[i][j];
			}
		}
		g.swap(tp);
		swap(n, m);
	}
	vector<int> p, cnt;
	long long ans = 0;
	cnt.assign(2 * B+10, 0);
	for (int u = 0; u < n; u++) {
		p.assign(m, 0);
		for (int d = u; d < n; d++) {
			for (int c = 0; c < m; c++) {
				if (g[d][c] == '#') p[c]++;
				else p[c]--;
			}
			int sm = 0;

			cnt[B] = 1;
			for (int c = 0; c < m; c++) {
				sm += p[c];
				ans += cnt[sm + B];
				cnt[sm + B]++;
			}
			cnt[B] = 0;
			sm = 0;
			for (int c = 0; c < m; c++) {
				sm += p[c];
				cnt[sm + B] = 0;
			}
		}
	}
	cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		slove();
	}
	return 0;
}