#include <bits/stdc++.h>
using namespace std;
int n, k, r[9];
vector<vector<int>> ve;
vector<int> tmp;
void dfs(int key, int sum) {
	if (key == n) {
		if (sum % k == 0) ve.push_back(tmp);
		return;
	}
	for (int i = 1; i <= r[key]; i++) {
		tmp[key] = i;
		dfs(key + 1, sum + i);
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> r[i];
	tmp.resize(n);
	dfs(0, 0);
	sort(ve.begin(), ve.end());
	for (auto p : ve) {
		for (int i : p)
			printf("%d ", i);
		putchar('\n');
	}
	return 0;
}
