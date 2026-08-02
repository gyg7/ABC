#include <bits/stdc++.h>
using namespace std;
int n, p[1 << 18];
void devdiv(int l, int r) {
	if (l >= r) return;
	int mid = (l + r) / 2;
	int mnl = 0x3f3f3f3f, mnr = 0x3f3f3f3f;
	for (int i = l; i <= mid; i++) {
		mnl = min(mnl, p[i]);
	}
	for (int i = mid + 1; i <= r; i++) {
		mnr = min(mnr, p[i]);
	}
	if (mnr < mnl) {
		for (int i = l, j = r; i < j; i++, j--) {
			swap(p[i], p[j]);
		}
	}
	devdiv(l, mid);
	devdiv(mid + 1, r);

}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < (1 << n); j++) {
			cin >> p[j];
		}
		devdiv(0, (1 << n) -1);
		for (int j = 0; j < (1 << n); j++) {
			cout << p[j] << " \n"[j == ((1 << n) -1)];
		}
	}
	return 0;
}