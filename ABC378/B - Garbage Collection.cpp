#include <bits/stdc++.h>
using namespace std;
int n, r[101], q[101], p, t, d;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> q[i] >> r[i];
	cin >> p;
	for (int _ = 1; _ <= p; _++) {
		cin >> t >> d;
		for (int j = -1;q[t] * j + r[t] < d; j++) {
			if (q[t] * (j + 1) + r[t] >= d) {
				cout << q[t]*(j + 1) + r[t] << endl;
				break;
			}
		}
	}
	return 0;
}