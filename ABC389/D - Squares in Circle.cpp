#include <bits/stdc++.h>
using namespace std;
long long r, j, ans;
double f(double x, double y) {
	return x * x + y * y;
}
double F(int x, int y) {
	return max({f(x + .5, y + .5), f(x + .5, y - .5), f(x - .5, y + .5), f(x - .5, y - .5)});
}
int main() {
	cin >> r;
	j = r;
	for (int i = 0; i <= r; i++) {
		while (j && F(i, j) > r * r) j--;
		ans += j;
	}
	cout << ans * 4 + 1 << endl;
}