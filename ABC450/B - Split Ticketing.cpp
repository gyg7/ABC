#include <bits/stdc++.h>
using namespace std;
int n, a[110][110];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++)
			cin >> a[i][j];
	}
	int num = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			for (int k = j + 1; k <= n; k++)
				if (a[i][j] + a[j][k] < a[i][k])
					num++;
	if (num) puts("Yes");
	else puts("No");
}