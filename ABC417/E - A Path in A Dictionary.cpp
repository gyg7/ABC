#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int t, n, m, x, y, S, T;
int mp[N][N];
int sk[N], top, vis[N];
bool dfs(int u, int fa) {
	if (u == T) {
		sk[++top] = u;
		return true;
	}
	vis[u] = 1;
	for (int v = 1; v <= n; v++) {
		if (v == fa || vis[v] || mp[u][v] == 0) continue;
		if (dfs(v, u)) {
			sk[++top] = u;
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d", &t);
	for (int _ = 1; _ <= t; _++) {
		scanf("%d%d%d%d", &n, &m, &S, &T);
		for (int i = 1; i <= n; i++)
			vis[i] = 0;
		memset(mp, 0, sizeof mp);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &x, &y);
			mp[x][y] = mp[y][x] = true;
        }
		dfs(S, -1);
		while (top) {
			printf("%d ", sk[top]);
			top--;
		}
		putchar('\n');
	}
	return 0;
}
