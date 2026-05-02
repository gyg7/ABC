#include <bits/stdc++.h>
using namespace std;
int n, x, y;
vector<int> ve[300001];
map<int,int> ch[3000001];
int node[30000001], tot;
void dfs(int u) {
	if (u) {
		for (int i : ve[u])
			cout << i << " ";
	}
	for (auto [k,v] : ch[u])
		dfs(v);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		if (ch[node[x]][y] == 0)
			ch[node[x]][y] = ++tot;
		node[i] = ch[node[x]][y];
		ve[node[i]].push_back(i);
	}
	dfs(0);
}