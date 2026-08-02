#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1;; i++) {
		int x = n % m;
		m = x;
		if (x == 0) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}