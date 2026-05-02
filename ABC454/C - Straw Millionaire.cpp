#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
vector<int> ve[300010];
bool vis[300010];
void dfs(int u) {
    if(vis[u]) return;
    vis[u]=1;ans++;
	for (int v : ve[u]) {
        dfs(v);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		ve[a].push_back(b);
	}
	dfs(1);
	cout << ans << endl;
}