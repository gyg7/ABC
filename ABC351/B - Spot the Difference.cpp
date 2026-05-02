#include <bits/stdc++.h>
using namespace std;
int n;
char a[101][101], b;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> b;
			if (b != a[i][j]) {
				printf("%d %d", i, j);
				return 0;
			}
		}
}