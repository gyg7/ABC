#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[101];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		a[i] = -1;
	for (int i = 1; i <= n; i++) {
		int c, x;
		cin >> c >> x;
		a[c] = max(a[c], x);
	}
	for (int i = 1; i <= m; i++) {
		cout << a[i] << " \n"[i == m];
	}
	return 0;
}