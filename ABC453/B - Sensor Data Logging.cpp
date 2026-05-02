#include <bits/stdc++.h>
using namespace std;
int n, x, a, b;
int main() {
	cin >> n >> x;
	b = -x;
	for (int i = 0; i <= n; i++) {
		cin >> a;
		if (abs(a - b) >= x) {
			b = a;
			cout << i << " " << a << endl;
		}
	}
	return 0;
}