#include <bits/stdc++.h>
using namespace std;
int a, b, c, n;
int main() {
	cin >> n >> a >> b;
	for (int i = 3; i <= n; i++) {
		cin >> c;
		if (a == b && b == c) {
			cout << "Yes";
			return 0;
		}
		a = b;
		b = c;
	}
	puts("No");
	return 0;
}