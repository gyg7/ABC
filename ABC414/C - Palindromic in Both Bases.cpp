#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
ll a, n;
ll sum;
ll fun(int x, int z, int p) {
	ll y = (p == 0 ? x : x * 10ll + z);
	while (x) {
		y = y * 10 + x % 10ll;
		x /= 10;
	}
	return y;
}
bool cmp(ll x) {
	int  num[80] = {0}, len = 0;
	while (x) {
		num[++len] = x % a;
		x /= a;
	}
	for (int i = 1; i <= len - i + 1; i++)
		if (num[i] != num[len - i + 1])
			return false;
	return true;
}
unordered_set<int> se;
signed main() {
	cin >> a >> n;
	for (int i = 0; i <= 1000000; i++) {
		for (int j = 0; j <= 9; j++) {
			ll y = fun(i, j, 1);
			if (y > n) break;
			if (se.count(y)) continue;
			se.insert(y);
			if (cmp(y)) sum += y;
		}
		ll y = fun(i, 0, 0);if (y > n) break;
		if (se.count(y)) continue;
		se.insert(y);
		
		if (cmp(y)) sum += y;
	}
	cout << sum << endl;
	return 0;
}
