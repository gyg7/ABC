#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int a[101];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> x;
			a[j] -= x;
		}
	for (int i = 1; i <= m; i++) {
		if (a[i] > 0) {
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}