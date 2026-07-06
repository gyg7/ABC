#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
int n;
struct point {
	int x, y;
} p[300010];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	sort(p + 1, p + 1 + n, [&](point a, point b) {
		return a.x < b.x;
	});
	atcoder::fenwick_tree<int> tree(n + 1);
	int ans  = 0;
	for (int i = 1; i <= n; i++) {
		if (tree.sum(0, p[i].y)) ans++;
		tree.add(p[i].y, 1);
	}
	cout << n - ans << endl;
	return 0;
}