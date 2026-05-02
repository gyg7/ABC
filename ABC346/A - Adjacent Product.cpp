#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;
int main() {
	cin >> n >> a;
	for (int i = 1; i <= n - 1; i++) {
		cin >> b;
		c = a * b;
		a = b;
		printf("%d ", c);
	}
}