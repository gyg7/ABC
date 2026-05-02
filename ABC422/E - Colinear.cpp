#include <bits/stdc++.h>
using namespace std;
#define int long long
int T = 1;
int n;
int x[500001], y[500001];
bool work(int i, int j) {
	int a = (y[i] - y[j]), b = (x[j] - x[i]), c = x[i] * y[j] - x[j] * y[i];
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (a * x[i] + b * y[i] + c == 0) ++cnt;
	return cnt * 2 >= n;
}
mt19937_64 rm(58);

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	for (int i = 1; i <= 100; i++) {
		int p, q;
		do {
			p = rm() % n + 1, q = rm() % n + 1;
		} while (p == q);
		if (work(p, q)) {
			int a = (y[p] - y[q]), b = (x[q] - x[p]), c = x[p] * y[q] - x[q] * y[p];
			puts("Yes");
			printf("%lld %lld %lld\n", a, b, c);
			return;
		}
	}
	puts("No");
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	if (false) {
		freopen("file.in", "r", stdin);
		freopen("file.out", "w", stdout);
	}
	//cin >> T;
	while (T--) solve();
	return 0;
}


