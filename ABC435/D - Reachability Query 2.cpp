#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, m, x, y, q;
vector<int> ve[N], reg[N];
bool seeblack[N];
int low[N], dfn[N], Time, bel[N], idx;
int st[N], top;
bool vis[N];
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void tarjan(int u) {
	low[u] = dfn[u] = ++Time;
	st[++top] = u;
	vis[u] = true;
	for (int v : ve[u]) {
		if (dfn[v] == 0) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (vis[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		int v;
		++idx;
		do {
			v = st[top--];
			vis[v] = false;
			bel[v] = idx;
		} while (v != u);
	}
}
queue<int> que;
int main() {
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		x = read(), y = read();
		ve[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
		if (dfn[i] == 0) tarjan(i);
	for (int u = 1; u <= n; u++) {
		for (int v : ve[u]) {
			if (bel[u] == bel[v]) continue;
			reg[bel[v]].push_back(bel[u]);
		}
	}
	for (int i = 1; i <= idx; i++) {
		sort(reg[i].begin(), reg[i].end());
		reg[i].erase(unique(reg[i].begin(), reg[i].end()), reg[i].end());
	}
	q = read();
	for (int i = 1; i <= q; i++) {
		int opt, v;
		opt = read(), v = read();
		if (opt == 1) {
			if (!seeblack[bel[v]]) {
				que.push(bel[v]);
				seeblack[bel[v]] = 1;
				while (que.size()) {
					int u = que.front();
					que.pop();
					for (int v : reg[u]) {
						if (seeblack[v] == 0) {
							que.push(v);
							seeblack[v] = 1;
						}
					}
				}
			}
		} else {
			printf(seeblack[bel[v]] ? "Yes\n" : "No\n");
		}
	}
}