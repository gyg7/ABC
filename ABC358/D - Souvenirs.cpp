#include <bits/stdc++.h>
using namespace std;
int n, m, a[200001], b[200001];
int j;
long long ans;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	j = 1;
	for (int i = 1; i <= n; i++) {
		if (j == m + 1) break;
		if (b[j] <= a[i]) {
			ans += a[i];
			j++;
		}
	}
	if (j == m + 1)
		printf("%lld", ans);
	else printf("-1");
}
