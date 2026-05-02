#include <bits/stdc++.h>
using namespace std;
int n, a[99][99], r, c;
int main() {
	cin >> n;
	a[r = 0][c = (n - 1) / 2] = 1;
	for (int i = 2; i <= n * n; i++) {
		if (a[(r - 1+n) % n][(c + 1) % n] == 0)
			a[r = (r - 1+n) % n][c = (c + 1) % n] = i;
		else a[r = (r + 1) % n][c] = i;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " \n"[j == n - 1];
}