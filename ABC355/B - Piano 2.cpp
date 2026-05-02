#include <bits/stdc++.h>
using namespace std;
int n, m, a[101], b, mp[201];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]] = 1;
	}
	for (int i = 1; i <= m; i++) {
		cin >> b;
		mp[b] = 2;
	}
	int j = 2;
	for (int i = 1; i <= 199; i++)
		if (mp[i] == 1)
			for (int j = i + 1; j <= 200; j++)
				if (mp[j] == 1) {
					printf("Yes\n");
					return 0;
				} else if (mp[j] == 2)
					break;
	printf("No");
}