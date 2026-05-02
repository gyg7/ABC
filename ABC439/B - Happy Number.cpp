#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n >= 10) {
		int d = n / 1000 % 10, c = n / 100 % 10, b = n / 10 % 10, a = n / 1 % 10;
		n = d * d + c * c + b * b + a * a;
	}
	cout << ((n == 1) ? "Yes" : "No") << endl;
}