#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int u, v;
vector<int> ve[200001];
void add(int u, int v) {
	for (int x : ve[u])
		if (x == v) {
			++ans;
			return;
		}
	ve[u].push_back(v);
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		if (u > v) swap(u, v);
		if (u == v) ans++;
		else add(u, v);
	}
	cout << ans << endl;
	return 0;
}