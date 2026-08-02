#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010];
ll gcd(ll n, ll m) {
	return !m ? n : gcd(m, n % m);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		ll x;
		cin >> n >> x;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int m = 1;
		for (int i = 2; i <= n; i++) {
			if (a[m] > a[i]) a[++m] = a[i];
		}
		ll l = 1;
		for (int i = 1; i <= m; i++) {
			l = l / gcd(l, a[i]) * a[i];
		}
		cout << l << endl;
		cout << x / l << endl;
	}
	return 0;
}
