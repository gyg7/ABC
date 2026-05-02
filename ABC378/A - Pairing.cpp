#include <bits/stdc++.h>
using namespace std;
int a[5], vis[5], ans;
int main() {
	for (int i = 1; i <= 4; i++)
		cin >> a[i];
	for (int i = 1; i <= 4; i++)
		if (vis[i] == 0)
			for (int j = i + 1; j <= 4; j++)
				if (a[i] == a[j] && vis[j] == 0) {
					vis[i] = vis[j] = 1;
					ans++;
					break;
				}
	cout << ans;
	return 0;
}