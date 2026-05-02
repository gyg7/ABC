#include <bits/stdc++.h>
using namespace std;
int n, l, r;
int main() {
	cin >> n >> l >> r;
	for (int i = 1; i < l; i++)
		printf("%d ", i);
	for (int i = r; i >= l; i--)
		printf("%d ", i);
	for (int i = r + 1; i <= n; i++)
		printf("%d ", i);
	putchar('\n');
	return 0;
}