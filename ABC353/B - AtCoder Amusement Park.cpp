#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, cnt;
int main() {
	cin >> n >> k;
	++cnt;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x + m <= k) m += x;
		else {
			++cnt;
			m = x;
		}
	}
	printf("%d", cnt);
}