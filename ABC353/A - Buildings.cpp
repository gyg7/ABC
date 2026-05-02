#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
	cin >> n >> a;
	for (int i = 2; i <= n; i++) {
		cin >> b;
		if (a < b) {
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}