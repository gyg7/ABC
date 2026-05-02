#include <bits/stdc++.h>
using namespace std;
void gettrace(int n, int m, int a, int b) {
	if (n == 2 && m == 2) {
		if (a == 1 && b == 2) printf("DR");
		else printf("RD");
		return;
	}
	if (a > 2) {
		for (int i = 1; i < m; i++) putchar('R');
		putchar('D');
		for (int i = 1; i < m; i++) putchar('L');
		putchar('D');
		gettrace(n - 2, m, a - 2, b);
		return;
	}
	if (b > 2) {
		for (int i = 1; i < n; i++) putchar('D');
		putchar('R');
		for (int i = 1; i < n; i++) putchar('U');
		putchar('R');
		gettrace(n, m - 2, a, b - 2);
		return ;
	}
	if (a <= n - 2) {
		gettrace(n - 2, m, a, b);
		putchar('D');
		for (int i = 1; i < m; i++) putchar('L');
		putchar('D');
		for (int i = 1; i < m; i++) putchar('R');
		return;
	}
	if (b <= m - 2) {
		gettrace(n, m - 2, a, b);
		putchar('R');
		for (int i = 1; i < n; i++) putchar('U');
		putchar('R');
		for (int i = 1; i < n; i++) putchar('D');
		return;
	}
}
void Solve() {
	int n, a, b;
	cin >> n >> a >> b;
	if (n % 2) {
		puts("No");
		return;
	}
	if ((a + b) % 2 == 0) {
		puts("No");
		return;
	}
	puts("Yes");
	gettrace(n, n, a, b);
	puts("");
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		Solve();
	}
}