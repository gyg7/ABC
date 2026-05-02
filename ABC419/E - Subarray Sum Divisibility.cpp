#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, l;
int a[501];
int f[501][501];
int g[501][501];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= l; i++)
		for (int j = 0; j < m; j++) {
			for (int p = i; p <= n; p += l)
				f[i][j] += (j-a[p] + m) % m;
		}
	memset(g, 0x3f, sizeof g);
	g[0][0] = 0;
	for (int i = 1; i <= l; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < m; k++)
				g[i][j] = min(g[i][j], g[i - 1][(j - k + m) % m] + f[i][k]);
	cout << g[l][0] << endl;
	return 0;
}

