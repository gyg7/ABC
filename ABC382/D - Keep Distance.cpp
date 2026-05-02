#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt;
vector<vector<int>> a;
vector<int> b;
void dfs(int cur) {
	if (cur == n + 1) {
		++cnt;
		a.push_back(b);
		return;
	}
	int begin  = cur == 1 ? 1 : b[cur - 1] + 10;
	for (int i = begin; i <= m - (n - cur) * 10; i++) {
		b[cur] = i;
		dfs(cur + 1);
		b[cur] = 0;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	b.resize(n + 1);
	dfs(1);
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}