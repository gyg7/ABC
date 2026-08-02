#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200010;
int n, m;
int a[N], b[N], c[N];
ll calc(int x1) {
	int x = x1;
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		ans += x;
		x = (c[i] + m - x) % m;
	}
	return ans + x;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i < n; i++) {
		c[i] = (b[i] - a[i] - a[i + 1]+2*m) % m;
	}
	ll ans = min(calc(0), calc(1));
	cout << ans << endl;
	return 0;
}