#include <bits/stdc++.h>
using namespace std;
int n, k;
struct mat {
	long long a[101][101];
};
mat a;
mat expow(mat a, mat b) {
	mat c;
	memset(c.a, 0x3f, sizeof c.a);
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) 
				c.a[i][j] = min(c.a[i][j], a.a[i][k] + b.a[k][j]);
	return c;
}
mat res;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a.a[i][j];
		res=a;
		k--;
	while (k) {
		if (k & 1) res = expow(res, a);
		a = expow(a, a);
		k >>= 1;
	}
	for (int i = 1; i <= n; i++) cout << res.a[i][i] << endl;
}