#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll a[500001], d[500001];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	ll sm = a[n] - a[1];
	for (int i = 1; i < n; i++) {
		d[i] = a[i + 1] - a[i];
	}
	sort(d + 1, d + n, greater<ll>());
	for (int i = 1; i < min(n, m); i++) {
		sm -= d[i];
	}
	cout << sm << endl;
	return 0;
}