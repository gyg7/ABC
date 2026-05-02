#include <bits/stdc++.h>
using namespace std;
const int N = 10001;
int n, p[N], a[N], b[N], q, x;
struct seg {
	int lsa, lsb, rsa, rsb;
} root;
int tot = 0, sum;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> a[i] >> b[i];
		sum += b[i];
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> x;
		if (x >= n * 500)
			cout << x - sum << endl;
		else {
			for (int j = 1; j <= n; j++) {
				if (p[j] >= x) x = 1 * x + a[j];
				else x = max(0, 1 * x - b[j]);
			}
			cout << x << endl;
		}
	}

	return 0;
}
