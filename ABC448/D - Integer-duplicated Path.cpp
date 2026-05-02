#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N], u, v;
vector<int> ve[N];
bool ans[N];
unordered_map<int, int> unmap;
void dfs(int u, int ff) {
	if (unmap[a[u]]) ans[u] = 1;
	unmap[a[u]]++;
	for (int v : ve[u])
		if (v != ff) {
			ans[v] |= ans[u];
			dfs(v, u);
		}
	unmap[a[u]]--;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++) {
		if (ans[i]) puts("Yes");
		else puts("No");
	}
}