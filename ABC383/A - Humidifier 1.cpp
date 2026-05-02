#include <bits/stdc++.h>
using namespace std;
int n, t, a, old, tot;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t >> a;
		if (old == 0) old = t;
		tot = max(0,tot - (t - old)) + a;
		old=t;
	}
	printf("%d", tot);
	return 0;
}