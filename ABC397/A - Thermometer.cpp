#include <bits/stdc++.h>
using namespace std;
double x;
int sgn(double x) {
	if (fabs(x) <= 1e-6) return 0;
	return x < 0 ? -1 : 1;
}
int main() {
	cin >> x;
	if (sgn(x - 38) >= 0) {
		cout << 1 << endl;
	} else if (sgn(x - 37.5) >= 0) {
		cout << 2 << endl;
	} else cout << 3 << endl;
	return 0;
}
