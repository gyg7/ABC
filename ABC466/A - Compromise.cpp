#include <bits/stdc++.h>
using namespace std;
int n, x;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x >= 0) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}