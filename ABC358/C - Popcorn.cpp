#include <bits/stdc++.h>
using namespace std;
int s[11], u, n, m, ans = 12, vis[11], b[11];
char ch;
void dfs(int deep, int x) {
	if (ans < deep - 1) return;
	if (x == u) {
		ans = deep - 1;
	}
	for (int i = b[deep - 1] + 1; i <= n; i++) {
		if (vis[i] == 0) {
			b[deep] = i;
			vis[i] = 1;
			dfs(deep + 1, x | s[i]);
			vis[i] = 0;
		}
	}
}
int main() {
	cin >> n >> m;
	u = (1 << m) - 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> ch;
			if (ch == 'o')
				s[i] |= (1 << (j - 1));
		}
	dfs(1, 0);
	printf("%d", ans);
}