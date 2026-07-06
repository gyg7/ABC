#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[60][60];
int main() {
	cin >> n >> m;
	int tx = n + 1, ty = m + 1, dx = 0, dy = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') {
				tx = min(tx, i);
				dx = max(dx, i);
				ty = min(ty, j);
				dy = max(dy, j);
			}
		}
	}
	for (int i = tx; i <= dx; i++) {
		for (int j = ty; j <= dy; j++) {
			cout << a[i][j];
		}
        cout<<endl;
	}
	return 0;
}