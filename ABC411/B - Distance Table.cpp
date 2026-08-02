#include <bits/stdc++.h>
using namespace std;
int n, d[60][60];
int main() {
	cin >> n;
	memset(d, 0x3f, sizeof d);
	for (int i = 1; i <= n; i++) {
		d[i][i] = 0;
	};
	for (int i = 1; i < n; i++) {
		cin >> d[i][i + 1];
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cout << d[i][j] << " \n"[j == n];
		}
	}
	return 0;
}