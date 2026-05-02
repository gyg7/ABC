#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, a[N], st[N][80];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
		st[i][0] = a[i];
	for (int j = 1; j < 80; j++)
		for (int i = 1; i <= n; i++)
			st[i][j] = st[st[i][j - 1]][j - 1];
	for (int i = 1; i <= n; i++) {
		int x = i;
		for (int j = 79; j >= 0; j--)
			x = st[x][j];
		printf("%d ", x);
	}
}