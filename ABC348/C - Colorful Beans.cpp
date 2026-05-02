#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
int n, a[maxn], c[maxn], newc[maxn], val[maxn], ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &c[i]);
		newc[i] = c[i];
	}
	sort(c + 1, c + 1 + n);
	int cnt = unique(c + 1, c + 1 + n) - (c + 1);
	for (int i = 1; i <= n; i++) {
		newc[i] = lower_bound(c + 1, c + 1 + cnt, newc[i]) - c;
		if (val[newc[i]] == 0 || val[newc[i]] > a[i])
			val[newc[i]] = a[i];
	}
	for (int i = 1; i <= cnt; i++)
		if (ans == 0 || (val[i] && val[i] > ans))
			ans = val[i];
	printf("%d", ans);
}