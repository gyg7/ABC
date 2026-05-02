#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
	cin >> n >> k;
	for (int i = 0;; i++) {
		if (1ll * (2*n + i) * (i + 1) >= 1ll * k * 2) {
			cout << i << endl;
			return 0;
		}
	}
}