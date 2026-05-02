#include <bits/stdc++.h>
using namespace std;
int n, a[100001], w[100001], c[100001];
long long sum;
int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		sum += w[i];
		c[a[i]] = max(c[a[i]], w[i]);
	}
	for (int i = 1; i <= n; i++)
		sum -= c[i];
	printf("%lld\n", sum);
	return 0;
}