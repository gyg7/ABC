#include <bits/stdc++.h>
using namespace std;
int a[110];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	bool ans1 = true, ans2 = true;
	for (int i = 1; i <= m; i++) {
		if (a[i] >= 2) {
			ans1 = 0;
		}
		if (a[i] == 0) {
			ans2 = 0;
		}
	}
	puts(ans1 ? "Yes" : "No");
	puts(ans2 ? "Yes" : "No");
}