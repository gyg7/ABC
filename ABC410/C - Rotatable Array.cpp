#include <bits/stdc++.h>
using namespace std;
int n, q, a[1000001], opt, p, x, k, dx;
int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) a[i] = i;
	for (int i = 1; i <= q; i++) {
		cin >> opt;
		if (opt == 1) {
			cin >> p >> k;
			a[(p + dx - 1) % n + 1] = k;
		}
		if (opt == 2) {
			cin >> p;
			cout << a[(p + dx - 1) % n + 1] << endl;
		}
		if (opt == 3) {
			cin >> k;
			dx = (dx + k) % n;
		}
	}
	return 0;
}
