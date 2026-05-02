#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, a[10];
ll dfs(int i, int sum, bool limit) {
	if (i == 0) return sum == 0;
	ll res = 0;
	int up = limit == 0 ? 9 : a[i];
	for (int d = 0; d <= up && sum - d >= 0; d++) {
		ll val = dfs(i - 1, sum - d, limit && d == up);
		res += val;
	}
	return res;
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= 9; i++) {
		a[i] = n % 10;
		n /= 10;
	}
	for (int i = 9; i > 0; i--) {
		if (a[i]) {
			cout << dfs(i, k, true) << endl;
			break;
		}
	}
	return 0;
}