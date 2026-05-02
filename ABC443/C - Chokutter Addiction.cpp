#include <bits/stdc++.h>
using namespace std;
int n, t, a, lst, ans;
int main() {
	cin >> n >> t;
	lst = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		ans += max(0, a - lst);
		if (lst <= a)
			lst = a + 100;
	}
	ans += max(0, t - lst);
	cout << ans << endl;
}