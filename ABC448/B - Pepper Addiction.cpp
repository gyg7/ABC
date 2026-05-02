#include <bits/stdc++.h>
using namespace std;
int n, m, a[1001], b, c;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	int res = 0;
	for (int i = 1; i <= n; i++) {
		cin >> b >> c;
		int rem = min(c, a[b]);
		a[b] -= rem;
		res += rem;
	}
	cout << res << endl;
}