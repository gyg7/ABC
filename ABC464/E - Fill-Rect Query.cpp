#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n, m, q, a[N];
char x[200001];
inline int pos(int x, int y) {
	if (x < 0 || x > n || y < 0 || y > m) return 0;
	return (x - 1) * m + y;
}
int main() {
	cin >> n >> m >> q;
	for (int i = 1; i <= q; i++) {
		int r, c;
		cin >> r >> c >> x[i];
		a[pos(r, c)] = i;
	}
	x[0] = 'A';
	for (int i = n * m; i >= 1; i--) {
		int r = (i - 1) / m + 1;
		int c = (i - 1) % m + 1;
		a[i] = max({a[i], a[pos(r + 1, c)], a[pos(r, c + 1)]});
	}
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= m; c++) {
			cout << x[a[pos(r, c)]];
		}
		cout << endl;
	}
	return 0;
}