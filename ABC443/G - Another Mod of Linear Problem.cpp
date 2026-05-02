#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int, int> divdie(int x, int y) {
	int b = x % y;
	if (b < 0) b += y;
	return {(x - b) / y, b};
}
int f(int n, int a, int b, int c) {
	auto [a1, a2] = divdie(a, c);
	auto [b1, b2] = divdie(b, c);
	int s = n * (n - 1) / 2 * a1;
	if (a2 == 0) return s + b1 * n;
	auto [k, _] = divdie(a2 * (n - 1) + b2, c);
	return s + n * (k + b1) - f(k, c, c + a2 - b2 - 1, a2);
}
signed main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, a, b, c;
		cin >> n >> c >> a >> b;
		cout << n - f(n, a, b, c) + f(n, a - 1, b - 1, c) << endl;;
	}
}