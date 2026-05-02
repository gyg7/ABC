#include <bits/stdc++.h>
using namespace std;
int n, a, num[1000001], ans;
int main() {
	cin >> n;
	ans = n + 1;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (num[a]) ans = min(ans, i - num[a] + 1);
		num[a] = i;
	}
	if (ans == n + 1) ans = -1;
	cout << ans << endl;
	return 0;
}