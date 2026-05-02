#include <bits/stdc++.h>
using namespace std;
long long x, res = 1;
int main() {
	cin >> x;
	for (int i = 2;; i++) {
		if (res * i == x) {
			cout << i << endl;
			return 0;
		}
		res *= (1ll * i);
	}
	
	return 0;
}