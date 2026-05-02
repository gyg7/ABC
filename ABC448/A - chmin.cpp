#include <bits/stdc++.h>
using namespace std;
int n, x, a;
int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (x > a) {
			puts("1");
			x = a;
		} else puts("0");
	}
}