#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int tr[2 * N], n, d[N];
string s;
int lb(int x) {
	return x & -x;
}
void add(int x, int v) {
	while (x <= 2 * n + 1) {
		tr[x] += v;
		x += lb(x);
	}
}
int sum(int x) {
	int res = 0;
	while (x) {
		res += tr[x];
		x -= lb(x);
	}
	return res;
}
int main() {
	cin >> n >> s;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		a += (s[i] == 'A');
		b += (s[i] == 'B');
		d[i + 1] = a - b;
	}
	long long ans = 0;
	for (int i = 0; i <= n; i++) {
		long long rem = sum(d[i] + n);
		ans += rem;
		add(d[i] + n + 1, 1);
	}
	cout << ans << endl;
}