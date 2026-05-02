#include <bits/stdc++.h>
using namespace std;
const int N  = 2e6 + 10;
int a[31], n, m, k;
int ch[30 * N][2], sz[30 * N], tot, num, head[N];
bool vis[N];
void insert(int x) {
	for (int i = 29; i >= 0; i--) {
		if ((x >> i) & 1) {
			if (a[i] == 0) {
				a[i] = x;
				return;
			} else  x ^= a[i];
		}
	}
}
int redus(int x) {
	for (int i = 29; i >= 0; i--)
		if ((x >> i) & 1) x ^= a[i];
	return x;
}
struct egde {
	int nxt, to, val;
} e[N];
void add(int u, int v, int w) {
	e[++num].nxt = head[u];
	e[head[u] = num].to = v;
	e[num].val = w;
}
void inserttrie(int x) {
	int cur = 1;
	for (int i = 29; i >= 0; i--) {
		sz[cur]++;
		int &c = ch[cur][(x >> i) & 1];
		if (c == 0) {
			c = ++tot;
			ch[c][0] = ch[c][1] = sz[c] = 0;
		}
		cur = c;
	}
	sz[cur]++;
}
int query(int x, int k) {
	int cur = 1, ans = 0;
	for (int i = 29; i >= 0; i--) {
		if (!cur) break;
		int c = (x >> i) & 1, c2 = (k >> i) & 1;
		if (c2) {
			ans += sz[ch[cur][c]];
			cur = ch[cur][c ^ 1];
		} else cur = ch[cur][c];
	}
	if (cur) ans += sz[cur];
	return ans;

}
int dist[N];
void dfs(int u, int p) {
	vis[u] = 1;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to, w = e[i].val;
		if (vis[v] == 0) {
			dist[v] = dist[u] ^ w;
			dfs(v, u);
		} else if(u!=p) insert(dist[v]^dist[u]^w);
	}
}
void readmeta() {
	cin >> n >> m >> k;
	num = 0;
	for (int i = 0; i < 30; i++) a[i] = 0;
	for (int i = 1; i <= n; i++) {
		vis[i] = dist[i] = 0;
		head[i] = 0;
	}
	tot = 1;
	num = 0;
	ch[1][0] = ch[1][1] = sz[1] = 0;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
}
void solve() {
	dfs(1, -1);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int res = redus(dist[i]);
		ans += query(res, k);
		inserttrie(res);
	}
	cout << ans << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		readmeta();
		solve();
	}
}