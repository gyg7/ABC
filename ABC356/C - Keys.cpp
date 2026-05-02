#include <bits/stdc++.h>
using namespace std;
int n, m, k, c, x;
long long ans;
int a[101];
char r[101];
int popcount(int x) {
	int res = 0;
	for (int i = 0; i <= 14; i++)
		if (x & (1 << i)) res++;
	return res;
}
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> c;
		for (int j = 1; j <= c; j++) {
			cin >> x;
			a[i] |= (1 << (x - 1));
		}
		cin >> r[i];
	}
	for (int i = 0; i < 1 << n; i++) {
		int ok = 1, z;
		for (int j = 1; j <= m; j++)
			if (((z = popcount(i & a[j])) < k && r[j] == 'o') || ( z >= k && r[j] == 'x')) {
				ok = 0;
				break;
			}
		ans += ok;
	}
	printf("%lld", ans);
}