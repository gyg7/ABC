#include <bits/stdc++.h>
using namespace std;
int n, l, r, x, y, cnt;
int main() {
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		if (x <= l && r <= y) ++cnt;
	}
	cout << cnt << endl;
	return 0;
}
