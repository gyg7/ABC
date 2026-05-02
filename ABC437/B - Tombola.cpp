#include <bits/stdc++.h>
using namespace std;
int h, w, n, a[4][6], b, p[100];
int main() {
	cin >> h >> w >> n;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++) {
		cin >> b;
		p[b]++;
	}
	int ans = 0;
	for (int i = 1; i <= h; i++) {
		int res = 0;
		for (int j = 1; j <= w; j++)
			if (p[a[i][j]]) ++res;
		ans = max(ans, res);
	}
	cout << ans << endl;
}