#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
long long n, k, x[maxn][64], a[maxn];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)		cin >> x[i][0];
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int j = 1; j <= 63; j++)
		for (int i = 1; i <= n; i++)
			x[i][j] = x[x[i][j - 1]][j - 1];
	for (int i = 1; i <= n; i++) {
		int j = i;
		for (int m = 63; m >= 0; m--)
			if (k & (1ll << m)) j = x[j][m];
		cout << a[j] << " ";
	}
	return 0;
}
