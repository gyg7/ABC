#include <bits/stdc++.h>
using namespace std;
int n, a[101], ve[101][101], num[101], ans[101], r;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ve[a[i]][++num[a[i]]] = i;
	}
	r = 1;
	for (int i = 100; i >= 1; i--) {
		for (int j = 1; j <= num[i]; j++)
			ans[ve[i][j]] = r;
		r += num[i];
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << endl;
	return 0;
}