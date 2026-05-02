#include <bits/stdc++.h>
using namespace std;
int n, m, ho;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> ho;
		if (m - ho < 0) {
			printf("%d", i - 1);
			return 0;
		}
		m -= ho;
	}
	printf("%d", n);
	return 0;
}