#include <bits/stdc++.h>
using namespace std;
#define dist(i,j) (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])
int n, x[101], y[101];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &x[i], &y[i]);
	for (int i = 1; i <= n; i++) {
		int ans = i;
		for (int j = 1; j <= n; j++)
			if (dist(i, ans) < dist(i, j)) ans  = j;
		printf("%d\n", ans);
	}
}