#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, m, x, y, cnt1, cnt2;
vector<int> ve[N];
int vis[N], vis2[N];
void dfs(int u, int mx) {
    vis[u]=1;++cnt1;
	for (int v : ve[u]) {
		if (v <= mx && vis[v] == 0) 
			dfs(v, mx);
		if (vis2[v] == 0) {
			vis2[v] = 1;
			++cnt2;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		if (x == y) continue;
		ve[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		if (i == 1){vis2[i] = 1;++cnt2;}
		if (vis2[i]) dfs(i, i);
		if (cnt1 < i) puts("-1");
		else cout << cnt2 - cnt1 << endl;
	}
}