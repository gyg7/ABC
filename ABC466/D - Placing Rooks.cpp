#include <bits/stdc++.h>
using namespace std;
int n, m, r[300001], c[300010];
unordered_set<int> row, col;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> r[i] >> c[i];
	}
	int count = 0;
	for (int i = m; i >= 1; i--) {
		if (row.count(r[i]) == 0 && col.count(c[i])==0) count++;
		row.insert(r[i]);
		col.insert(c[i]);
	}
	cout << count << endl;
	return 0;
}